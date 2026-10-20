#include "static/model.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "C3/control.h"
#include "C3/geoPalette.h"
#include "C3/anim.h"
#include "C3/actor.h"
#include "Dolphin/gx.h"
#include "static/static_80021188.h"
#include "static/static_8003A2EC.h"
#include "static/anim.h"
#include "static/static_80021AC8.h"
#include "static/static_80023B90.h"

typedef struct LightDesc {
    /* 0x0 */ u16 height;
    /* 0x2 */ u16 pitch;
    /* 0x4 */ u16 yaw;
    /* 0x6 */ u8 r;
    /* 0x7 */ u8 g;
    /* 0x8 */ u8 b;
} LightDesc;

typedef struct LightPos {
    /* 0x00 */ Vec pos;
    /* 0x0C */ GXColor color;
} LightPos;

typedef struct LITObj LITObj;

typedef struct _VecXYZ {
    f32 x, y, z;
} VecXYZ;

// STRUCTS BEGIN
typedef struct RosterEntry {
    /* 0x0000 */ u8 _0000[0x24 - 0x0];
    /* 0x0024 */ s16 _24;
    /* 0x0026 */ u8 _26;
    /* 0x0027 */ u8 _27;
    /* 0x0028 */ u8 _0028[0xA0 - 0x28];
} RosterEntry; // size: 0xA0

typedef struct AramEntry {
    /* 0x0000 */ u32 _00;
    /* 0x0004 */ u32 size;
    /* 0x0008 */ u32 _08;
    /* 0x000C */ u32 _0C;
} AramEntry; // size: 0x10

typedef struct ModelCamera {
    /* 0x0000 */ u8 _0000[0x40 - 0x0];
    /* 0x0040 */ Mtx view;
} ModelCamera; // size: 0x70

typedef struct JointPair {
    /* 0x0000 */ u16 a;
    /* 0x0002 */ u16 b;
} JointPair; // size: 0x4

typedef struct ModelEntry28 {
    /* 0x0000 */ void (*cb)(void);
    /* 0x0004 */ f32 _04;
    /* 0x0008 */ f32 _08;
    /* 0x000C */ f32 _0C;
    /* 0x0010 */ f32 _10;
    /* 0x0014 */ f32 _14;
    /* 0x0018 */ f32 _18;
    /* 0x001C */ u8 _001C[0x26 - 0x1C];
    /* 0x0026 */ u8 _26;
    /* 0x0027 */ u8 _0027[0x28 - 0x27];
} ModelEntry28; // size: 0x28

typedef struct ModelNode {
    /* 0x0000 */ u8 _0000[0x6 - 0x0];
    /* 0x0006 */ u16 numBones;
    /* 0x0008 */ u8 _0008[0x14 - 0x8];
    /* 0x0014 */ struct DODisplayObj* dispObj;
    /* 0x0018 */ struct ModelNode** bones;
    /* 0x001C */ u8 _001C[0x64 - 0x1C];
    /* 0x0064 */ MtxPtr skinMtx;
    /* 0x0068 */ MtxPtr skinInvMtx;
    /* 0x006C */ u8 _006C[0x74 - 0x6C];
    /* 0x0074 */ struct ModelNode* child;
    /* 0x0078 */ u8 _0078[0x7C - 0x78];
    /* 0x007C */ void* _7C;
    /* 0x0080 */ u16 joint;
    /* 0x0082 */ u8 _0082[0x98 - 0x82];
    /* 0x0098 */ u8 flags;
    /* 0x0099 */ u8 _99;
    /* 0x009A */ u8 _009A[0xEC - 0x9A];
    /* 0x00EC */ MtxPtr mtx;
    /* 0x00F0 */ u8 _00F0[0x100 - 0xF0];
    /* 0x0100 */ struct ModelNode* next;
} ModelNode; // size: 0x104

typedef struct LightSet {
    /* 0x0000 */ LightDesc lights[4];
    /* 0x0028 */ GXColor ambient;
} LightSet; // size: 0x2C

typedef struct ModelJoint {
    /* 0x0000 */ u8 _0000[0xEC - 0x0];
    /* 0x00EC */ MtxPtr mtx;
} ModelJoint; // size: 0xF0

typedef struct ModelData {
    /* 0x0000 */ u8 _0000[0x18 - 0x0];
    /* 0x0018 */ ModelJoint** joints;
} ModelData; // size: 0x1C

typedef struct ModelHandle {
    /* 0x0000 */ ModelData* data;
} ModelHandle; // size: 0x4

typedef struct ModelLink {
    /* 0x0000 */ u8 _0000[0x70 - 0x0];
    /* 0x0070 */ void* _70;
} ModelLink; // size: 0x74

typedef struct ModelTaskSub {
    /* 0x0000 */ u8 _0000[0x10 - 0x0];
    /* 0x0010 */ s16 _10;
    /* 0x0012 */ u8 _0012[0x14 - 0x12];
} ModelTaskSub; // size: 0x14

typedef struct ModelTask {
    /* 0x0000 */ u8 _0000[0xC - 0x0];
    /* 0x000C */ ModelTaskSub* _0C;
    /* 0x0010 */ u8 _0010[0x14 - 0x10];
    /* 0x0014 */ s8 _14;
    /* 0x0015 */ u8 _0015[0x18 - 0x15];
} ModelTask; // size: 0x18

typedef struct ModelLoadReq {
    /* 0x0000 */ u8 _0000[0x14 - 0x0];
    /* 0x0014 */ u8 _14;
    /* 0x0015 */ u8 _15;
    /* 0x0016 */ u8 _16;
    /* 0x0017 */ u8 _0017[0x19 - 0x17];
    /* 0x0019 */ u8 _19;
    /* 0x001A */ u8 _1A;
    /* 0x001B */ u8 _1B;
    /* 0x001C */ u8 _1C;
    /* 0x001D */ u8 _1D;
    /* 0x001E */ u8 _001E[0x20 - 0x1E];
} ModelLoadReq; // size: 0x20

typedef struct AnimState {
    /* 0x0000 */ void* hdr;
    /* 0x0004 */ u8 _0004[0x2C - 0x4];
    /* 0x002C */ void* file;
    /* 0x0030 */ u8 _0030[0x58 - 0x30];
    /* 0x0058 */ s8 current;
    /* 0x0059 */ u8 _0059[0x5C - 0x59];
} AnimState; // size: 0x5C

typedef struct ModelSub2C {
    /* 0x0000 */ void** files;
    /* 0x0004 */ AnimState state;
    /* 0x0060 */ u8 _60;
    /* 0x0061 */ s8 _61;
    /* 0x0062 */ u8 _0062[0x64 - 0x62];
} ModelSub2C; // size: 0x64

typedef struct ModelPose {
    /* 0x0000 */ u8 _0000[0x4 - 0x0];
    /* 0x0004 */ AnimState state;
    /* 0x0060 */ u8 _60;
    /* 0x0061 */ u8 _0061[0x68 - 0x61];
    /* 0x0068 */ AnimState state2;
    /* 0x00C4 */ u8 _C4;
    /* 0x00C5 */ u8 _00C5[0xD0 - 0xC5];
    /* 0x00D0 */ s8 _D0;
    /* 0x00D1 */ s8 _D1;
    /* 0x00D2 */ u8 _00D2[0xD4 - 0xD2];
} ModelPose; // size: 0xD4

typedef struct ModelActor {
    /* 0x0000 */ ModelNode* models[1];
    /* 0x0004 */ u8 _0004[0x8 - 0x4];
    /* 0x0008 */ u8* _08;
    /* 0x000C */ u8* _0C;
    /* 0x0010 */ void* anims[7];
    /* 0x002C */ ModelSub2C* _2C;
    /* 0x0030 */ ModelPose* _30;
    /* 0x0034 */ Vec pos;
    /* 0x0040 */ Vec _40;
    /* 0x004C */ f32 _4C;
    /* 0x0050 */ u8 _0050[0x5C - 0x50];
    /* 0x005C */ s32 _5C;
    /* 0x0060 */ s16 _60;
    /* 0x0062 */ s16 _62;
    /* 0x0064 */ s16 _64;
    /* 0x0066 */ s16 _66;
    /* 0x0068 */ s16 _68;
    /* 0x006A */ s16 _6A;
    /* 0x006C */ s16 _6C;
    /* 0x006E */ s16 _6E;
    /* 0x0070 */ s16 _70;
    /* 0x0072 */ u16 _72[120];
    /* 0x0162 */ u16 joints[120];
    /* 0x0252 */ s8 _252;
    /* 0x0253 */ u8 _0253[0x254 - 0x253];
    /* 0x0254 */ s8 _254;
    /* 0x0255 */ s8 _255;
    /* 0x0256 */ u8 _256;
    /* 0x0257 */ s8 _257;
    /* 0x0258 */ u8 _258;
    /* 0x0259 */ u8 _259;
    /* 0x025A */ u8 _25A;
    /* 0x025B */ u8 _25B;
    /* 0x025C */ s8 _25C;
    /* 0x025D */ u8 _25D;
    /* 0x025E */ s8 _25E;
    /* 0x025F */ s8 _25F;
    /* 0x0260 */ s8 _260;
    /* 0x0261 */ s8 _261;
    /* 0x0262 */ s8 _262;
    /* 0x0263 */ s8 _263;
    /* 0x0264 */ s8 _264;
    /* 0x0265 */ s8 _265;
    /* 0x0266 */ s8 _266;
    /* 0x0267 */ s8 _267;
    /* 0x0268 */ u8 _268;
    /* 0x0269 */ s8 _269;
    /* 0x026A */ s8 _26A;
    /* 0x026B */ s8 _26B;
    /* 0x026C */ u8 _026C[0x26D - 0x26C];
    /* 0x026D */ s8 _26D;
    /* 0x026E */ s8 _26E;
    /* 0x026F */ s8 _26F;
    /* 0x0270 */ u8 _0270[0x273 - 0x270];
    /* 0x0273 */ s8 _273;
    /* 0x0274 */ s8 _274;
    /* 0x0275 */ u8 _0275[0x277 - 0x275];
    /* 0x0277 */ u8 _277;
    /* 0x0278 */ s8 _278;
    /* 0x0279 */ u8 _0279[0x27C - 0x279];
} ModelActor; // size: 0x27C

typedef struct ModelSlot {
    /* 0x0000 */ ModelNode* node;
    /* 0x0004 */ ANIMBank* anim;
    /* 0x0008 */ void (*callback)(struct ModelSlot*);
    /* 0x000C */ u8 _000C[0xE - 0xC];
    /* 0x000E */ u16 seqNum;
    /* 0x0010 */ Control ctrl;
    /* 0x0054 */ f32 speed;
    /* 0x0058 */ u8 _58;
    /* 0x0059 */ u8 _59;
    /* 0x005A */ u8 _5A;
    /* 0x005B */ u8 _5B;
    /* 0x005C */ f32 time;
    /* 0x0060 */ f32 _60;
    /* 0x0064 */ u16 _64;
    /* 0x0066 */ u16 _66;
    /* 0x0068 */ u16* _68;
    /* 0x006C */ u8 _6C;
    /* 0x006D */ u8 numLights;
    /* 0x006E */ u8 _006E[0x70 - 0x6E];
    /* 0x0070 */ LITObj* lights[8];
} ModelSlot; // size: 0x90

typedef struct ModelTable {
    /* 0x0000 */ u16 count;
    /* 0x0002 */ u8 _0002[0x34 - 0x2];
    /* 0x0034 */ ModelSlot slots[1];
} ModelTable; // size: 0xC4

typedef struct ModelWork {
    /* 0x0000 */ u8 _0000[0x60 - 0x0];
    /* 0x0060 */ ModelTable* _0060;
    /* 0x0064 */ ModelTable* _0064;
    /* 0x0068 */ ModelTable* _0068;
    /* 0x006C */ ModelTable* _006C;
    /* 0x0070 */ u8 _0070[0xAC - 0x70];
    /* 0x00AC */ LITObj* lights[4];
    /* 0x00BC */ u8 _00BC[0x13C - 0xBC];
    /* 0x013C */ ModelTable* _013C;
    /* 0x0140 */ ModelPose poses[13];
    /* 0x0C04 */ ModelActor actorData[13];
    /* 0x2C50 */ ModelActor* actors[13];
    /* 0x2C84 */ void** files;
    /* 0x2C88 */ void* _2C88;
    /* 0x2C8C */ u8* _2C8C;
    /* 0x2C90 */ u8 _2C90[0x2CA4 - 0x2C90];
    /* 0x2CA4 */ u32 bufSize;
    /* 0x2CA8 */ u8 _2CA8[0x2CB0 - 0x2CA8];
    /* 0x2CB0 */ void* _2CB0[4];
    /* 0x2CC0 */ u8 _2CC0[0x2CE4 - 0x2CC0];
    /* 0x2CE4 */ void* _2CE4;
    /* 0x2CE8 */ void* _2CE8;
    /* 0x2CEC */ u8 _2CEC[0x2CFC - 0x2CEC];
    /* 0x2CFC */ void* _2CFC;
    /* 0x2D00 */ u8 _2D00[0x2D10 - 0x2D00];
    /* 0x2D10 */ void* _2D10;
    /* 0x2D14 */ u8 _2D14[0x2D24 - 0x2D14];
    /* 0x2D24 */ void* _2D24;
    /* 0x2D28 */ u8 _2D28[0x2D38 - 0x2D28];
    /* 0x2D38 */ void* _2D38;
    /* 0x2D3C */ void* _2D3C;
    /* 0x2D40 */ u8 _2D40[0x2D44 - 0x2D40];
    /* 0x2D44 */ s16 _2D44;
    /* 0x2D46 */ u8 _2D46;
    /* 0x2D47 */ u8 _2D47[0x2D48 - 0x2D47];
    /* 0x2D48 */ void* _2D48;
    /* 0x2D4C */ u8 _2D4C[0x2D50 - 0x2D4C];
    /* 0x2D50 */ s16 _2D50;
    /* 0x2D52 */ u8 _2D52;
    /* 0x2D53 */ u8 _2D53[0x2D54 - 0x2D53];
    /* 0x2D54 */ void* _2D54;
    /* 0x2D58 */ u8 _2D58[0x2D5C - 0x2D58];
    /* 0x2D5C */ s16 _2D5C;
    /* 0x2D5E */ u8 _2D5E;
    /* 0x2D5F */ u8 _2D5F[0x2D64 - 0x2D5F];
    /* 0x2D64 */ u32 _2D64;
    /* 0x2D68 */ s16 _2D68;
    /* 0x2D6A */ s8 _2D6A[13];
    /* 0x2D77 */ s8 _2D77;
    /* 0x2D78 */ u8 _2D78[0x2D79 - 0x2D78];
    /* 0x2D79 */ s8 _2D79;
    /* 0x2D7A */ u8 _2D7A[0x2D89 - 0x2D7A];
    /* 0x2D89 */ s8 _2D89[4];
    /* 0x2D8D */ u8 _2D8D;
    /* 0x2D8E */ u8 _2D8E[0x2D90 - 0x2D8E];
    /* 0x2D90 */ ModelEntry28* _2D90;
    /* 0x2D94 */ ModelEntry28* _2D94;
    /* 0x2D98 */ void* _2D98;
    /* 0x2D9C */ s32* _2D9C;
    /* 0x2DA0 */ void* _2DA0[3];
    /* 0x2DAC */ u8 _2DAC[0x3074 - 0x2DAC];
    /* 0x3074 */ void (*_3074)(MtxPtr);
    /* 0x3078 */ u16 _3078;
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B;
    /* 0x307C */ u8 _307C;
    /* 0x307D */ u8 _307D[0x307E - 0x307D];
    /* 0x307E */ u8 _307E;
    /* 0x307F */ u8 _307F[0x3082 - 0x307F];
    /* 0x3082 */ s8 _3082;
    /* 0x3083 */ u8 _3083[0x3085 - 0x3083];
    /* 0x3085 */ u8 _3085;
    /* 0x3086 */ u8 _3086[0x3088 - 0x3086];
    /* 0x3088 */ u8 _3088;
    /* 0x3089 */ u8 _3089[0x308C - 0x3089];
    /* 0x308C */ void (*_308C)(void);
    /* 0x3090 */ u8 _3090[0x309C - 0x3090];
    /* 0x309C */ AnimState anim0;
    /* 0x30F8 */ AnimState anim1;
} ModelWork; // size: 0x3154

// STRUCTS END

extern ModelWork lbl_8036E548;
extern RosterEntry inMemRoster[2][9];
extern u8 lbl_803CBC3C[4];
extern u8 lbl_8036C4FC[0x204C];
extern u8 lbl_803CBBC0;
extern ModelActor* lbl_803CBC18;
void fn_800B9AA8(void*);
extern s32 lbl_803CBBF0;
extern ModelLoadReq* lbl_803CC1B8;
extern ModelSub2C lbl_80118220[13];
extern LightPos lbl_80367318[4];
extern LightSet lbl_800F7478[];
extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ u8 _715;
} lbl_803C6CF8;
extern struct {
    /* 0x000 */ u8 _000[0x1E8];
    /* 0x1E8 */ u8 _1E8;
} lbl_803716B8;
void fn_800BEBCC(s32 id, Vec* dir);
void fn_800B2D5C(ModelNode* node);
void LITAlloc(LITObj** light);
void LITInitAttn(LITObj* light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2);
void LITInitPos(LITObj* light, f32 x, f32 y, f32 z);
void LITInitColor(LITObj* light, GXColor color);
void fn_800BD2DC(void);
void fn_8004B6EC(ModelActor* actor, ModelSlot* slot);
void fn_8004B7F4(ModelActor* actor);
void fn_8004BAEC(ModelActor* actor, ModelSlot* slot);
void fn_8005240C(ModelActor* actor, ModelSlot* slot);
void fn_800B2BA8(ModelNode* node, u16 joint, ModelNode* src, u16 bone);
ModelTable* ActorObjectInitTable(s32 count);
void fn_800BDC88(ModelTable* table, u16 slot, u16 id, void* layout, s32 arg4, s32 arg5);
void convertTextureHeader(void* tex);
void GXSetCurrentGXThread(void);
void LITInitDir(LITObj* light, f32 nx, f32 ny, f32 nz);
void LITXForm(LITObj* light, Mtx view);
void fn_80052694(s32 idx);
s32 fn_8005268C(void);
void fn_8003414C(Mtx m);
void minigamesGXStuff(void);
void fn_800BD670(ModelTable* table, MtxPtr view);
void fn_800BDA94(ModelSlot* slot, MtxPtr view);
void fn_800B9948(s32 arg0);
void fn_800B993C(void);
void LoadActorLayout(void* layout);
void convertGeometryAndSknHeader(void* geo, void* skn);
void haveActLayoutPointToGeoHeader(void* layout, void* geo);
void fn_800BD190(void* geo, void* tex);
void fn_800238E0(ModelTable* group, u16 slot, s16 id, void* layout);
void fn_800B4CA0(ModelNode* node, f32 time);
void fn_800B4C04(ModelNode* node, f32 speed);
void fn_800B4AFC(ModelNode* node, u8 arg1);
void Set_FUN_800b2b6c(ModelNode* node, u16* arg1);
void fn_800BDA24(ModelSlot* slot);
s32 fn_800527BC(void);
ModelCamera* fn_80052734(s32 idx);
u8 fn_800B3C04(s32 idx, ModelNode* node, Mtx m);
void fn_800BD2CC(s32 id, GXColor color);
void fn_800BD548(ModelSlot* slot, s32 count, ...);
void fn_800B2C10(ModelNode* node, u16 joint, Vec* out);
void fn_800B2C44(ModelNode* node, u16 joint, Vec* out);

extern AramEntry lbl_800F1D78[];
extern u8 lbl_800F71D8[];
extern u8 lbl_800F5D98[];

AramEntry* lbl_803CB790 = lbl_800F1D78;
u8* lbl_803CB794 = lbl_800F71D8;
JointPair lbl_803CB798[2] = { { 0x4A, 0x4B }, { 0xFFFF, 0 } };
JointPair lbl_803CB7A0[2] = { { 0x2F, 0x34 }, { 0xFFFF, 0 } };
u8* lbl_803CB7A8 = lbl_800F5D98;
void (*lbl_803CB7AC[2])(MtxPtr view, s32, u32) = { 0 };
u8 lbl_803CB7B4[8] = { 0x13, 0x19, 0x14, 0x1A, 0x4A, 0x4B, 0x3C, 0x3D };
f32 lbl_803CB7BC = 2.0f;
u8 lbl_803CB7C0 = 0x20;
u8 lbl_803CB7C1 = 0xFF;
u8 lbl_803CB7C2 = 1;
u8 lbl_803CB7C4[4] = { 0, 1, 2, 3 };

static u8 lbl_800EE800[0x110] = {
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
};
AramEntry lbl_800EE910[2] = {
    { 0x0000040B, 0x40093FF8, 0x0E581000, 0x0005F484 },
    { 0x0000040B, 0x40095BB8, 0x0E5E0800, 0x0006053C },
};
u32 lbl_800EE930[4] = {
    0x0000040B, 0x40001640, 0x08EB4800, 0x00000C38,
};
u32 lbl_800EE940[8] = {
    0x0000040B, 0x400B2D00, 0x08EB5800, 0x0006A948, 0x00000000, 0x00000686, 0x08F20800, 0x00000688,
};
static JointPair lbl_800EE960[14] = {
    0x0016, 0x0010, 0x0017, 0x0011, 0x0018, 0x0012, 0x0019, 0x0013, 0x001A, 0x0014, 0x001B, 0x0015,
    0x0020, 0x001C, 0x0021, 0x001D, 0x0022, 0x001E, 0x0023, 0x001F, 0x0026, 0x0025, 0x0028, 0x0027,
    0x003D, 0x003C, 0xFFFF, 0x0000,
};
static JointPair lbl_800EE998[6] = {
    0x002F, 0x0034, 0x0030, 0x0035, 0x0031, 0x0036, 0x0032, 0x0037, 0x0033, 0x0038, 0xFFFF, 0x0000,
};
static JointPair lbl_800EE9B0[7] = {
    0x0041, 0x0047, 0x0042, 0x0048, 0x0043, 0x0049, 0x0044, 0x004A, 0x0045, 0x004B, 0x0046, 0x004C,
    0xFFFF, 0x0000,
};
u16 lbl_800EE9CC[70] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000E, 0x000F,
    0x000D, 0x000C, 0x000B, 0x000A, 0x0016, 0x0017, 0x0018, 0x0019, 0x001A, 0x001B, 0x0010, 0x0011,
    0x0012, 0x0013, 0x0014, 0x0015, 0x0020, 0x0021, 0x0022, 0x0023, 0x001C, 0x001D, 0x001E, 0x001F,
    0x0024, 0x0026, 0x0025, 0x0028, 0x0027, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B,
    0x003D, 0x003C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
u8 lbl_800EEA58[0x54] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x00, 0x0E,
    0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x00, 0x00,
};
s16 lbl_800EEAAC[54] = {
    0x0000, 0x0006, 0x000C, 0x0012, 0x0018, 0x001E, 0x0024, 0x002A, 0x0030, 0x0036, 0x003C, 0x0042,
    0x0048, 0x004E, 0x0054, 0x005A, 0x0060, 0x0066, 0x006C, 0x0072, 0x0078, 0x007E, 0x0084, 0x008A,
    0x0090, 0x0096, 0x009C, 0x00A2, 0x00A8, 0x00AE, 0x00B4, 0x00BA, 0x00C0, 0x00C6, 0x00CC, 0x00D2,
    0x00D8, 0x00DE, 0x00E4, 0x00EA, 0x00F0, 0x00F6, 0x00FC, 0x0102, 0x0108, 0x010E, 0x0114, 0x011A,
    0x0120, 0x0126, 0x012C, 0x0132, 0x0138, 0x013E,
};
s16 lbl_800EEB18[54] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A, 0x000B,
    0x000C, 0x000D, 0xFFFF, 0x000E, 0xFFFF, 0x000F, 0x0010, 0x0011, 0x0012, 0x0013, 0x0013, 0x0013,
    0x0014, 0x0014, 0x0014, 0x0015, 0x0016, 0x000D, 0x000D, 0x000D, 0x000D, 0x0017, 0x0017, 0x0017,
    0x0017, 0xFFFF, 0xFFFF, 0x0019, 0x001A, 0x001B, 0x000C, 0x0012, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0x001C, 0x001C, 0x001C, 0x001C, 0x0015, 0x0015,
};

static inline int getActorJoint(ModelActor* actor, int i) {
    if (actor != NULL) {
        return actor->joints[i];
    }
    return 0xFFFF;
}

static inline Vec setSlotJoints(u16 slot, u16 a, u16 b) {
    Vec v;
    ModelTable* table = lbl_8036E548._0060;
    ModelNode* node = table->slots[slot].node;

    fn_800B2C44(node, node->joint, &v);
    table->slots[slot]._64 = a;
    table->slots[slot]._66 = b;
    return v;
}

// .text:0x8001FDD4 size:0x2C
void fn_8001FDD4(ModelLink* arg0) {
    if (arg0->_70 != NULL) {
        fn_800B9AA8(arg0->_70);
    }
}

static inline void mirrorJointPairs(ModelActor* actor, JointPair* list) {
    u16 b;
    u16 a;
    JointPair* pairs;

    for (pairs = list; pairs->a != 0xFFFF; pairs++) {
        a = actor->joints[pairs->a];
        b = actor->joints[pairs->b];
        if (a != 0xFFFF && b != 0xFFFF) {
            actor->_72[a] = b;
            actor->_72[b] = a;
        }
    }
}

// .text:0x8001FC4C size:0x188
void fn_8001FC4C(ModelActor* actor) {
    JointPair* list;
    s32 i;
    u16 a;
    u16 b;

    for (i = 0; i < 120; i++) {
        actor->_72[i] = i;
    }
    i = 0;
    do {
        a = actor->joints[lbl_800EE960[i].a];
        b = actor->joints[lbl_800EE960[i].b];
        if (a != 0xFFFF && b != 0xFFFF) {
            actor->_72[a] = b;
            actor->_72[b] = a;
        }
    } while (lbl_800EE960[++i].a != 0xFFFF);
    switch (actor->_252) {
    case 20:
    case 43:
        list = lbl_803CB798;
        break;
    case 41:
        list = lbl_800EE998;
        break;
    case 17:
        list = lbl_803CB7A0;
        break;
    case 16:
    case 44:
    case 45:
    case 46:
    case 47:
        list = lbl_800EE9B0;
        break;
    default:
        list = NULL;
        break;
    }
    if (list != NULL) {
        mirrorJointPairs(actor, list);
    }
}

// .text:0x8001F8A4 size:0x3A8
// 79.92%: first draft from m2c; saved registers differ throughout and the slot setup
// in the type >= 16 branch is scheduled differently. Not yet tuned.
void fn_8001F8A4(void) {
    u8* type;
    void* geo;
    void* tex;
    int i;
    u16 k;
    void* layout;
    ModelSlot* slot;

    for (i = 0; i < 24; i++) {
        layout = lbl_8036E548.files[i * 3 + 0];
        geo = lbl_8036E548.files[i * 3 + 1];
        tex = lbl_8036E548.files[i * 3 + 2];
        LoadActorLayout(layout);
        convertGeometryAndSknHeader(geo, NULL);
        haveActLayoutPointToGeoHeader(layout, geo);
        if (i == 11) {
            tex = lbl_8036E548.files[32];
        } else {
            convertTextureHeader(tex);
        }
        fn_800BD190(geo, tex);
    }
    ANIMGet(lbl_8036E548.files[72]);
    fn_80025DDC(lbl_8036E548.files[76]);
    lbl_8036E548.anim0.hdr = lbl_8036E548.files[77];
    fn_80025FFC(lbl_8036E548.files[76], &lbl_8036E548.anim0);
    fn_80025EEC(&lbl_8036E548.anim0, 0, 0);
    fn_80025DDC(lbl_8036E548.files[78]);
    lbl_8036E548.anim1.hdr = lbl_8036E548.files[79];
    fn_80025FFC(lbl_8036E548.files[78], &lbl_8036E548.anim1);
    fn_80025EEC(&lbl_8036E548.anim1, 0, 0);
    lbl_8036E548._0064 = ActorObjectInitTable(25);
    type = lbl_800EEA58;
    for (k = 0; k < 25; k++) {
        if (*type < 16) {
            fn_800BDC88(lbl_8036E548._0064, k, k, lbl_8036E548.files[*type * 3], 0, 0);
        } else {
            fn_800BDC88(lbl_8036E548._0064, k, k, lbl_8036E548.files[*type * 3], (s32)lbl_8036E548.files[72], 0);
            slot = &lbl_8036E548._0064->slots[k];
            slot->seqNum = 0;
            slot->time = 0.0f;
            slot->_58 = 1;
            slot->_59 = slot->_5A = slot->anim != NULL;
            slot->_60 = 0.0f;
            ACTSetAnimation((Actor*)slot->node, slot->anim, NULL, slot->seqNum, 0.0f, slot->_60);
            fn_800B4AFC(slot->node, 0);
        }
        if (*type == 0 || *type == 4 || (u8)(*type - 7) <= 3 || (u8)(*type - 12) <= 6 || *type == 19) {
            fn_800BD548(&lbl_8036E548._0064->slots[k], 4, lbl_8036E548.lights[0], lbl_8036E548.lights[1], lbl_8036E548.lights[2], lbl_8036E548.lights[3]);
        } else {
            fn_800BD548(&lbl_8036E548._0064->slots[k], 0);
        }
        CTRLSetTranslation(&lbl_8036E548._0064->slots[k].ctrl, 0.0f, 0.0f, 0.0f);
        CTRLSetRotation(&lbl_8036E548._0064->slots[k].ctrl, 0.0f, 0.0f, 0.0f);
        if (k == 5) {
            fn_80025C58(lbl_8036E548.anim0.file, (struct Model*)&lbl_8036E548._0064->slots[k]);
        } else if (k == 6) {
            fn_80025C58(lbl_8036E548.anim1.file, (struct Model*)&lbl_8036E548._0064->slots[k]);
        }
        type++;
    }
    lbl_8036E548._2D90 = _OSAllocFromHeap(32, 25 * sizeof(ModelEntry28));
    for (i = 0; i < 25; i++) {
        lbl_8036E548._2D90[i]._04 = 0.0f;
        lbl_8036E548._2D90[i]._08 = 0.0f;
        lbl_8036E548._2D90[i]._0C = 0.0f;
        lbl_8036E548._2D90[i]._10 = 0.0f;
        lbl_8036E548._2D90[i]._14 = 0.0f;
        lbl_8036E548._2D90[i]._18 = 0.0f;
        lbl_8036E548._2D90[i]._26 = 0;
        lbl_8036E548._2D90[i].cb = NULL;
    }
}

// .text:0x8001F5E8 size:0x2BC
// 64.90%: the target reloads _2DA0[0..2] after storing them and keeps 30 in r31 for
// ActorObjectInitTable and the allocation; this build forwards the stored values.
void fn_8001F5E8(void) {
    void* layout;
    void* geo;
    void* tex;
    s32 count = 30;
    u16 i;
    s32 j;

    lbl_8036E548._3078 = 30;
    for (i = 0; i < 3; i++) {
        lbl_8036E548._2DA0[i] = (u8*)lbl_8036E548._2D9C + lbl_8036E548._2D9C[i];
    }
    layout = lbl_8036E548._2DA0[0];
    geo = lbl_8036E548._2DA0[1];
    tex = lbl_8036E548._2DA0[2];
    LoadActorLayout(layout);
    convertGeometryAndSknHeader(geo, NULL);
    haveActLayoutPointToGeoHeader(layout, geo);
    convertTextureHeader(tex);
    fn_800BD190(geo, tex);
    lbl_8036E548._0068 = ActorObjectInitTable(count);
    for (i = 0; i < 30; i++) {
        fn_800BDC88(lbl_8036E548._0068, i, i, lbl_8036E548._2DA0[0], 0, 0);
        fn_800BD548(&lbl_8036E548._0068->slots[i], 4, lbl_8036E548.lights[0], lbl_8036E548.lights[1], lbl_8036E548.lights[2], lbl_8036E548.lights[3]);
        CTRLSetTranslation(&lbl_8036E548._0068->slots[i].ctrl, 0.0f, 0.0f, 0.0f);
        CTRLSetRotation(&lbl_8036E548._0068->slots[i].ctrl, 0.0f, 0.0f, 0.0f);
    }
    lbl_8036E548._2D94 = _OSAllocFromHeap(32, count * sizeof(ModelEntry28));
    for (j = 0; j < count; j++) {
        lbl_8036E548._2D94[j]._04 = 0.0f;
        lbl_8036E548._2D94[j]._08 = 0.0f;
        lbl_8036E548._2D94[j]._0C = 0.0f;
        lbl_8036E548._2D94[j]._10 = 0.0f;
        lbl_8036E548._2D94[j]._14 = 0.0f;
        lbl_8036E548._2D94[j]._18 = 0.0f;
        lbl_8036E548._2D94[j]._26 = 0;
        lbl_8036E548._2D94[j].cb = NULL;
    }
}

// .text:0x8001F4C0 size:0x128
void challengeMapMaybe(void) {
    int i;

    for (i = 0; i < 13; i++) {
        ModelActor* a = &lbl_8036E548.actorData[i];
        a->_25C = 0;
        a->_25D = 0;
        a->_4C = 0.5f;
        a->_60 = 0;
        a->_62 = 0;
        a->_64 = 0;
        a->_6A = 0;
        a->_25E = 1;
        a->_268 = 0;
        a->_273 = 0;
        a->_274 = 0;
        a->_278 = 0;
        a->_5C = 0;
        a->pos.x = 0.0f;
        a->pos.y = 0.0f;
        a->pos.z = 0.0f;
        a->_40.x = 0.0f;
        a->_40.y = 0.0f;
        a->_40.z = 0.0f;
        a->_70 = -1;
    }
    for (i = 0; i < 13; i++) {
        if (lbl_8036E548.actors[i] != NULL) {
            lbl_8036E548.actors[i]->_25C = 1;
        }
    }
    for (i = 0; i < 25; i++) {
        lbl_8036E548._2D90[i]._26 = 0;
        lbl_8036E548._2D90[i]._04 = 0.0f;
        lbl_8036E548._2D90[i]._08 = 0.0f;
        lbl_8036E548._2D90[i]._0C = 0.0f;
        lbl_8036E548._2D90[i]._10 = 0.0f;
        lbl_8036E548._2D90[i]._14 = 0.0f;
        lbl_8036E548._2D90[i]._18 = 0.0f;
    }
    lbl_8036E548._3078 = 0;
}

// .text:0x8001F228 size:0x298
void fn_8001F228(void) {
}

// .text:0x8001F16C size:0xBC
// 99.15%: registers only; the loop counter and the actors[] pointer swap r28/r30.
void fn_8001F16C(void) {
    ModelTable* table;
    ModelSlot* slot;
    int i;

    if (lbl_8036E548._307A != 0 && lbl_8036E548._307A != 3) {
        table = lbl_8036E548._0060;
        for (i = 0; i < table->count; i++) {
            if (lbl_8036E548.actors[i] != NULL) {
                slot = &lbl_8036E548._0060->slots[lbl_8036E548.actors[i]->_255];
                if (slot->node != NULL && slot->_6C != 0) {
                    fn_800B2D5C(slot->node);
                }
            }
        }
    }
}

static inline void drawSceneCallback(s32 cam, s32 pass) {
    if (lbl_803CB7AC[!lbl_803CBBC0] != NULL) {
        lbl_803CB7AC[!lbl_803CBBC0](fn_80052734(cam)->view, pass, 1);
    }
}

static inline void drawSceneCallbackLast(s32 cam) {
    if (lbl_803CB7AC[!lbl_803CBBC0] != NULL) {
        lbl_803CB7AC[!lbl_803CBBC0](fn_80052734(cam)->view, 1, 1);
        lbl_803CB7AC[!lbl_803CBBC0] = NULL;
    }
}

static inline void drawExtraModels(void) {
    ModelSlot* slot;
    u16 i;

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetCullMode(GX_CULL_BACK);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    for (i = 0; i < lbl_8036E548._0068->count; i++) {
        slot = &lbl_8036E548._0068->slots[i];
        if (slot->node != NULL && slot->_6C != 0) {
            if (lbl_8036E548._2D94[i].cb != NULL) {
                lbl_8036E548._2D94[i].cb();
            }
            fn_800BDA94(slot, fn_80052734(0)->view);
        }
    }
}

static inline void drawMinigameOverlay(void) {
    fn_8003414C(fn_80052734(fn_8005268C())->view);
    minigamesGXStuff();
}

// .text:0x8001E784 size:0x9E8
// 98.34%: as fn_8001CE74, the light pointer and GXColor temporaries; drawExtraModels
// tests the slot through its element base while the call takes &slots[i].
void fn_8001E784(void) {
    Vec dir;
    LightPos* light;
    s32 i;
    int j;

    GXSetCurrentGXThread();
    if (lbl_8036E548._307A != 0) {
        light = lbl_80367318;
        if (lbl_8036E548._3085 != 0) {
            fn_800BD2CC(lbl_800F7478[g_d_GameSettings._54].ambient.a != 0, lbl_800F7478[g_d_GameSettings._54].ambient);
            for (j = 0; j < 4; j++) {
                LITInitAttn(lbl_8036E548.lights[j], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
                LITInitPos(lbl_8036E548.lights[j], light->pos.x, light->pos.y, light->pos.z);
                LITInitColor(lbl_8036E548.lights[j], light->color);
                dir.x = light->pos.x;
                dir.y = light->pos.y;
                dir.z = light->pos.z;
                PSVECNormalize(&dir, &dir);
                LITInitDir(lbl_8036E548.lights[j], dir.x, dir.y, dir.z);
                LITXForm(lbl_8036E548.lights[j], fn_80052734(0)->view);
                light++;
            }
        }
        i = fn_800527BC() - 1;
        do {
            fn_80052694(i);
            if (lbl_8036E548._307A == 3) {
                drawSceneCallback(i, 0);
                drawSceneCallbackLast(i);
                if (lbl_8036E548._3078 != 0) {
                    drawExtraModels();
                }
                if (lbl_8036E548._307E != 0) {
                    drawMinigameOverlay();
                }
            } else if (lbl_8036E548._307A == 5) {
                fn_8001E488();
            } else if (lbl_8036E548._307A == 2) {
                GXSetZCompLoc(GX_FALSE);
                fn_8001E0D8(lbl_8036E548._0060, i, fn_80052734(i)->view);
            } else if (lbl_8036E548._307A == 4) {
                fn_8001E0D8(lbl_8036E548._0060, i, fn_80052734(i)->view);
                if (lbl_8036E548._3078 != 0) {
                    drawExtraModels();
                }
                drawMinigameOverlay();
            } else if (lbl_8036E548._307A != 0) {
                drawSceneCallback(i, 0);
                if (lbl_8036E548._307C != 0) {
                    fn_8001E0D8(lbl_8036E548._0060, i, fn_80052734(i)->view);
                    fn_800BD670(lbl_8036E548._0064, fn_80052734(i)->view);
                    if (lbl_8036E548._3078 != 0) {
                        drawExtraModels();
                    }
                    if (lbl_8036E548._3074 != NULL) {
                        lbl_8036E548._3074(fn_80052734(i)->view);
                        lbl_8036E548._3074 = NULL;
                    }
                }
                drawSceneCallbackLast(i);
                if (lbl_8036E548._307E != 0) {
                    drawMinigameOverlay();
                }
            }
        } while (i-- != 0);
        GXSetScissor(0, 0, 640, 448);
    } else {
        if (lbl_8036E548._3088 != 0 && lbl_8036E548._307E != 0) {
            drawSceneCallback(0, 0);
            drawSceneCallbackLast(0);
        }
        drawMinigameOverlay();
    }
}

// .text:0x8001E488 size:0x2FC
void fn_8001E488(void) {
    Mtx44 proj;
    ModelActor* actor;
    ModelSlot* slot;
    f32 x;
    f32 y;
    int i;

    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetCullMode(GX_CULL_BACK);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    for (i = 0; i < lbl_8036E548._0060->count; i++) {
        actor = lbl_8036E548.actors[i];
        if (actor != NULL) {
            slot = &lbl_8036E548._0060->slots[i];
            if (slot->node != NULL && slot->_6C != 0) {
                x = actor->pos.x / 1280.0f;
                y = actor->pos.y / 1280.0f;
                C_MTXFrustum(proj, -0.175f + y, 0.175f + y, 0.25f + x, -0.25f + x, 1.0f, 512.0f);
                GXSetProjection(proj, GX_PERSPECTIVE);
                fn_8001DEA4(slot, 0, fn_80052734(0)->view);
            }
        }
    }
}

// .text:0x8001E474 size:0x14
void fn_8001E474(void) {
    lbl_803CB7AC[0] = NULL;
    lbl_803CB7AC[1] = NULL;
}

// .text:0x8001E460 size:0x14
void fn_8001E460(void (*draw)(MtxPtr view, s32, u32)) {
    lbl_803CB7AC[lbl_803CBBC0] = draw;
}

// .text:0x8001E0D8 size:0x388
void fn_8001E0D8(ModelTable* table, int lod, MtxPtr camera) {
    Mtx m;
    GXColor ambient;
    ModelActor* actor;
    ModelSlot* slot;
    u16 i;
    u8 alpha;

    alpha = 0xFF;
    ambient = lbl_800F7478[g_d_GameSettings._54].ambient;
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetCullMode(GX_CULL_BACK);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    for (i = 0; i < table->count; i++) {
        actor = lbl_8036E548.actors[i];
        if (actor != NULL && actor->_25D != 2) {
            slot = &lbl_8036E548._0060->slots[actor->_255];
            if (slot->node != NULL && slot->_6C != 0) {
                if (alpha != actor->_277) {
                    alpha = actor->_277;
                    if (255 - alpha != 0) {
                        ambient.a = alpha;
                        if (alpha == 0) {
                            continue;
                        }
                        fn_800BD2CC(1, ambient);
                    } else {
                        fn_800BD2CC(1, lbl_800F7478[g_d_GameSettings._54].ambient);
                    }
                }
                PSMTXTrans(m, actor->pos.x, actor->pos.y, actor->pos.z);
                PSMTXConcat(camera, m, m);
                fn_800B9948(actor->_5C);
                lbl_803CBC18 = actor;
                fn_8001DEA4(slot, lod, m);
            }
        }
    }
    fn_800B993C();
}

// .text:0x8001DEA4 size:0x234
void fn_8001DEA4(ModelSlot* slot, int lod, MtxPtr camera) {
    ModelNode* node;

    node = slot->node;
    if (slot->callback != NULL) {
        slot->callback(slot);
    }
    switch (slot->numLights) {
    case 0:
        fn_8001DD58(node, lod, camera, 0);
        break;
    case 1:
        fn_8001DD58(node, lod, camera, 1, slot->lights[0]);
        break;
    case 2:
        fn_8001DD58(node, lod, camera, 2, slot->lights[0], slot->lights[1]);
        break;
    case 3:
        fn_8001DD58(node, lod, camera, 3, slot->lights[0], slot->lights[1], slot->lights[2]);
        break;
    case 4:
        fn_8001DD58(node, lod, camera, 4, slot->lights[0], slot->lights[1], slot->lights[2], slot->lights[3]);
        break;
    case 5:
        fn_8001DD58(node, lod, camera, 5, slot->lights[0], slot->lights[1], slot->lights[2], slot->lights[3], slot->lights[4]);
        break;
    case 6:
        fn_8001DD58(node, lod, camera, 6, slot->lights[0], slot->lights[1], slot->lights[2], slot->lights[3], slot->lights[4], slot->lights[5]);
        break;
    case 7:
        fn_8001DD58(node, lod, camera, 7, slot->lights[0], slot->lights[1], slot->lights[2], slot->lights[3], slot->lights[4], slot->lights[5], slot->lights[6]);
        break;
    case 8:
        fn_8001DD58(node, lod, camera, 8, slot->lights[0], slot->lights[1], slot->lights[2], slot->lights[3], slot->lights[4], slot->lights[5], slot->lights[6], slot->lights[7]);
        break;
    }
}

// .text:0x8001DD58 size:0x14C
void fn_8001DD58(ModelNode* node, int lod, MtxPtr camera, u8 numLights, ...) {
    va_list list;
    ModelNode* child;

    if (node->flags & (1 << (lod * 3))) {
        if (node->dispObj != NULL) {
            GXInvalidateVtxCache();
            va_start(list, numLights);
            if (node->_7C != NULL) {
                DOVARender(node->dispObj, camera, numLights, &list);
            } else {
                DOVARenderSkin(node->dispObj, camera, node->skinMtx, node->skinInvMtx, numLights, &list);
            }
        }
        for (child = node->child; child != NULL; child = child->next) {
            if (child->dispObj != NULL) {
                DOSetWorldMatrix(child->dispObj, child->mtx);
            }
            va_start(list, numLights);
            DOVARender(child->dispObj, camera, numLights, &list);
        }
    }
}

// .text:0x8001DB74 size:0x1E4
void fn_8001DB74(ModelTable* table) {
    Mtx m;
    ModelSlot* slot;
    u16 i;
    int shift;
    MtxPtr view;
    u16 j;
    ModelActor* actor;
    ModelNode* node;
    u8 mask;

    for (i = 0; i < table->count; i++) {
        actor = lbl_8036E548.actors[i];
        if (actor != NULL && actor->_25D != 0) {
            slot = &lbl_8036E548._0060->slots[actor->_255];
            if (slot->node != NULL) {
                if (slot->_58) {
                    ACTSetAnimation((Actor*)slot->node, slot->anim, NULL, slot->seqNum, 0.0f, slot->_60);
                }
                if (slot->_59) {
                    fn_800B4CA0(slot->node, slot->time);
                }
                if (slot->_5A) {
                    fn_800B4C04(slot->node, slot->speed);
                }
                if (slot->_5B & 2) {
                    fn_800B4AFC(slot->node, slot->_5B & 1);
                }
                Set_FUN_800b2b6c(slot->node, slot->_68);
                if (slot->_6C) {
                    fn_800BDA24(slot);
                }
                for (j = 0; j < fn_800527BC(); j++) {
                    view = fn_80052734(j)->view;
                    shift = j * 3;
                    mask = ~(3 << shift);
                    if (lbl_8036E548._307A == 5) {
                        slot->node->flags = 1;
                    } else {
                        PSMTXTrans(m, actor->pos.x, actor->pos.y, actor->pos.z);
                        PSMTXConcat(view, m, m);
                        node = slot->node;
                        node->flags = (node->flags & mask) | (fn_800B3C04(j, node, m) << shift);
                    }
                }
                slot->_58 = 0;
                slot->_59 = 0;
                slot->_5A = 0;
                slot->_5B &= 1;
            }
        }
    }
}

// .text:0x8001D2D4 size:0x8A0
void fn_8001D2D4(void) {
}

// .text:0x8001D180 size:0x154
// 95.35%: the target keeps a second copy of actor (mr r9,r6) for the loop body; this build
// uses one register, so the loop registers differ.
void fn_8001D180(int idx, int part, BOOL restore) {
    ModelActor* actor = lbl_8036E548.actors[idx];
    ModelPose* pose;
    ModelNode** p;
    ModelNode* model;
    ModelNode* bone;
    ModelNode* src;
    int joint;
    u16 n;
    int k;

    if (actor != NULL) {
        joint = actor->joints[lbl_803CB7B4[part]];
    } else {
        joint = 0xFFFF;
    }
    if (joint == 0xFFFF) {
        return;
    }
    k = 0;
    do {
        model = actor->models[k];
        if (!restore) {
            if (model != NULL) {
                bone = model->bones[joint];
                if (bone != NULL) {
                    bone->dispObj = NULL;
                }
            }
        } else if (lbl_800EEAAC[actor->_252] >= 0 && (pose = actor->_30) != NULL) {
            bone = model->bones[joint];
            if (part & 1) {
                src = lbl_8036E548._013C->slots[pose->_C4].node;
            } else {
                src = lbl_8036E548._013C->slots[pose->_60].node;
            }
            if (src == NULL) {
                return;
            }
            n = src->numBones;
            p = &src->bones[n];
            do {
                p--;
                n--;
                if ((*p)->dispObj != NULL) {
                    bone->dispObj = (*p)->dispObj;
                    return;
                }
            } while (n != 0);
            return;
        }
    } while (k-- != 0);
}

// .text:0x8001D148 size:0x38
void fn_8001D148(s32 idx, f32 x, f32 y, f32 z) {
    CTRLSetScale(&lbl_8036E548._0064->slots[idx].ctrl, x, y, z);
}

// .text:0x8001D110 size:0x38
void fn_8001D110(s32 idx, f32 x, f32 y, f32 z) {
    CTRLSetScale(&lbl_8036E548._0068->slots[idx].ctrl, x, y, z);
}

// .text:0x8001D0D0 size:0x40
void fn_8001D0D0(s32 idx, f32 scale) {
    CTRLSetScale(&lbl_8036E548._0068->slots[idx].ctrl, scale, scale, scale);
}

// .text:0x8001D074 size:0x5C
void fn_8001D074(s32 idx, BOOL on) {
    ModelActor* actor = lbl_8036E548.actors[idx];
    ModelNode* node;

    if (actor != NULL) {
        node = lbl_8036E548._0060->slots[actor->_255].node;
        if (on) {
            node->flags |= 4;
        } else {
            node->flags &= 0xFB;
        }
    }
}

// .text:0x8001CE74 size:0x200
// 96.59%: the target builds the light pointer straight into r31 (here r6 then mr) and
// swaps the stack slots of the two GXColor temporaries.
void fn_8001CE74(void) {
    LightPos* light = lbl_80367318;
    int id;
    int i;

    lbl_8036E548._3085 = 4;
    if (g_d_GameSettings.GameModeSelected == 7) {
        id = g_d_GameSettings.StadiumID + 7;
    } else {
        id = g_d_GameSettings.StadiumID;
    }
    fn_8001CA40(id);
    fn_800BD2DC();
    if (lbl_800F7478[g_d_GameSettings._54].ambient.a != 0) {
        fn_800BD2CC(1, lbl_800F7478[g_d_GameSettings._54].ambient);
    }
    for (i = 0; i < 4; i++) {
        LITAlloc(&lbl_8036E548.lights[i]);
        LITInitAttn(lbl_8036E548.lights[i], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        LITInitPos(lbl_8036E548.lights[i], light->pos.x, light->pos.y, light->pos.z);
        LITInitColor(lbl_8036E548.lights[i], light->color);
        light++;
    }
    if (lbl_8036E548._006C != NULL) {
        for (i = 0; i < lbl_8036E548._006C->count; i++) {
            fn_800BD548(&lbl_8036E548._006C->slots[i], 4, lbl_8036E548.lights[0], lbl_8036E548.lights[1], lbl_8036E548.lights[2], lbl_8036E548.lights[3]);
        }
    }
}

// .text:0x8001CCC8 size:0x1AC
void fn_8001CCC8(void) {
    LightPos* lights = lbl_80367318;
    int id;
    int i;

    lbl_8036E548._3085 = 4;
    if (g_d_GameSettings.GameModeSelected == 7) {
        id = g_d_GameSettings.StadiumID + 7;
    } else {
        id = g_d_GameSettings.StadiumID;
    }
    fn_8001CA40(id);
    fn_800BD2DC();
    if (lbl_800F7478[g_d_GameSettings._54].ambient.a != 0) {
        fn_800BD2CC(1, lbl_800F7478[g_d_GameSettings._54].ambient);
    }
    for (i = 0; i < 4; i++) {
        LITAlloc(&lbl_8036E548.lights[i]);
        LITInitAttn(lbl_8036E548.lights[i], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        LITInitPos(lbl_8036E548.lights[i], lights[i].pos.x, lights[i].pos.y, lights[i].pos.z);
        LITInitColor(lbl_8036E548.lights[i], lights[i].color);
    }
}

// .text:0x8001CBD4 size:0xF4
void fn_8001CBD4(void) {
    int id;

    if (g_d_GameSettings.GameModeSelected == 7) {
        id = g_d_GameSettings.StadiumID + 7;
    } else {
        id = g_d_GameSettings.StadiumID;
    }
    fn_8001CA40(id);
}

static inline void updateLightDir(void) {
    Vec pos;
    Vec dir;

    pos.x = lbl_80367318[0].pos.x;
    pos.y = lbl_80367318[0].pos.y;
    pos.z = lbl_80367318[0].pos.z;
    PSVECNormalize(&pos, &pos);
    dir = pos;
    fn_800BEBCC(0, &dir);
}

// .text:0x8001CB10 size:0xC4
void fn_8001CB10(LightDesc* desc, s32 count) {
    int i;

    for (i = 0; i < count; i++) {
        fn_80023B90(&desc[i], &lbl_80367318[i]);
    }
    updateLightDir();
}

// .text:0x8001CA40 size:0xD0
void fn_8001CA40(u8 set) {
    g_d_GameSettings._54 = set;
    fn_8001CB10(lbl_800F7478[set].lights, 4);
}

// .text:0x8001C920 size:0x120
BOOL fn_8001C920(int id) {
    int idx;

    if (lbl_803CBC3C[1] == 0) {
        if ((s32)lbl_803C6CF8._715 != 1) {
            goto fail;
        }
        lbl_803CBC3C[1] = 1;
    }
    if (lbl_803CBC3C[1] == 1) {
        if (g_d_GameSettings.minigamesEnabled || g_d_GameSettings.GameModeSelected == 2) {
            idx = id * 19 + 18;
        } else {
            idx = id * 19 + 5;
        }
        ARAMTransfer(&lbl_803CB790[idx], lbl_8036E548._2CE4, 0, 0);
        lbl_803CBC3C[1] = 2;
    } else if (lbl_803CBC3C[1] == 2 && (s32)lbl_803C6CF8._715 == 1) {
        ANIMGet(lbl_8036E548._2CE4);
        if (lbl_8036E548.actors[0]->anims[3] == NULL) {
            lbl_8036E548.actors[0]->anims[3] = lbl_8036E548._2CE4;
        }
        return TRUE;
    }
fail:
    lbl_803CBC3C[0] = 0;
    return FALSE;
}

// .text:0x8001C67C size:0x2A4
int fn_8001C67C_animation(int, int) {
}

// .text:0x8001C588 size:0xF4
BOOL fn_8001C588(int id) {
    if (lbl_803CBC3C[3] == 0) {
        if ((s32)lbl_803C6CF8._715 != 1) {
            goto fail;
        }
        lbl_803CBC3C[3] = 1;
    }
    if (lbl_803CBC3C[3] == 1) {
        ARAMTransfer(&lbl_803CB790[id * 19 + 6], lbl_8036E548._2CE8, 0, 0);
        lbl_803CBC3C[3] = 2;
    } else if (lbl_803CBC3C[3] == 2 && (s32)lbl_803C6CF8._715 == 1) {
        ANIMGet(lbl_8036E548._2CE8);
        if (lbl_8036E548.actors[1]->anims[4] == NULL) {
            lbl_8036E548.actors[1]->anims[4] = lbl_8036E548._2CE8;
        }
        return TRUE;
    }
fail:
    lbl_803CBC3C[0] = 0;
    return FALSE;
}

// .text:0x8001C528 size:0x60
void fn_8001C528(void) {
    int i;

    for (i = 0; i < 13; i++) {
        lbl_8036E548.actorData[i]._60 = -1;
        lbl_8036E548.actorData[i]._62 = -1;
        lbl_8036E548.actorData[i]._64 = -1;
        lbl_8036E548.actorData[i]._66 = -1;
        lbl_8036E548.actorData[i]._68 = 0;
        lbl_8036E548.actorData[i]._6A = 0;
        lbl_8036E548.actorData[i]._25E = 1;
        lbl_8036E548.actorData[i]._25F = 0;
        lbl_8036E548.actorData[i]._262 = 0;
        lbl_8036E548.actorData[i]._268 = 0;
        lbl_8036E548.actorData[i]._269 = 0;
        lbl_8036E548.actorData[i]._26A = 0;
        lbl_8036E548.actorData[i]._26B = 0;
        lbl_8036E548.actorData[i]._26F = 0;
    }
}

// .text:0x8001C234 size:0x2F4
void fn_8001C234(void) {
}

// .text:0x8001BE50 size:0x3E4
void fn_8001BE50(void) {
}

// .text:0x8001BA44 size:0x40C
void fn_8001BA44(int idx, int anim, int a, int b, int c, int d, int e) {
}

// .text:0x8001B990 size:0xB4
void AnimateCharacter(s32 idx, int anim, int a, u8 mode, int b, int c, int d, int e) {
    ModelActor* actor = lbl_8036E548.actors[idx];

    if (actor == NULL) {
        return;
    }
    if (mode == 1 && actor->_62 == anim) {
        return;
    }
    if (mode == 3) {
        mode = 1;
    }
    actor->_64 = anim;
    actor->_6C = c;
    actor->_260 = a;
    actor->_25E = mode;
    actor->_263 = b;
    actor->_266 = d;
    actor->_26D = 0;
    if (e == -1) {
        actor->_26A = 5;
    } else {
        actor->_26A = e;
    }
    actor->_66 = -1;
    if ((anim >= 0x3F && anim < 0x4B) || (anim >= 0x4B && anim < 0x69)) {
        lbl_8036E548.actors[idx]->_26D = 1;
    }
}

// .text:0x8001B918 size:0x78
void QueueCharacterAnimation(s32 idx, int anim, int a, int b, int c, int d, int e) {
    ModelActor* actor = lbl_8036E548.actors[idx];

    actor->_66 = anim;
    actor->_6E = c;
    actor->_261 = a;
    actor->_264 = b;
    actor->_267 = d;
    actor->_26E = 0;
    if (e == -1) {
        actor->_26B = 5;
    } else {
        actor->_26B = e;
    }
    if ((anim >= 0x3F && anim < 0x4B) || (anim >= 0x4B && anim < 0x69)) {
        lbl_8036E548.actors[idx]->_26E = 1;
    }
}

// .text:0x8001B80C size:0x10C
BOOL getAnimRelatedCoordinates(int idx, int joint, VecXYZ* out) {
    Vec v;
    ModelActor* actor = lbl_8036E548.actors[idx];
    ModelSlot* slot;
    int j;

    if (actor == NULL) {
        return FALSE;
    }
    j = getActorJoint(actor, joint);
    if (j == 0xFFFF) {
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 0.0f;
        return FALSE;
    }
    slot = &lbl_8036E548._0060->slots[actor->_255];
    fn_800B2C44(slot->node, j, &v);
    out->x = v.x;
    out->y = v.y;
    out->z = v.z;
    out->x = out->x + actor->pos.x;
    out->y = out->y + actor->pos.y;
    out->z = out->z + actor->pos.z;
    return TRUE;
}

// .text:0x8001B728 size:0xE4
BOOL fn_8001B728(int idx, int joint, Vec* out) {
    ModelActor* actor = lbl_8036E548.actors[idx];
    ModelSlot* slot;
    int j;

    if (actor == NULL) {
        return FALSE;
    }
    j = getActorJoint(actor, joint);
    if (j == 0xFFFF) {
        return FALSE;
    }
    slot = &lbl_8036E548._0060->slots[actor->_255];
    fn_800B2C10(slot->node, j, out);
    out->x = out->x + actor->pos.x;
    out->y = out->y + actor->pos.y;
    out->z = out->z + actor->pos.z;
    return TRUE;
}

// .text:0x8001B5EC size:0x13C
void fn_8001B5EC(int idx, BOOL alt) {
    ModelActor* actor = lbl_8036E548.actors[idx];

    if (actor != NULL) {
        int slot = actor->_255;
        if (!alt) {
            setSlotJoints(slot, getActorJoint(actor, 0), getActorJoint(actor, 4));
        } else {
            setSlotJoints(slot, getActorJoint(actor, 0), getActorJoint(actor, 0));
        }
    }
}

// .text:0x8001B4D8 size:0x114
void fn_8001B4D8(int idx, BOOL apply) {
    ModelActor* actor = lbl_8036E548.actors[idx];
    Vec d;

    if (actor != NULL) {
        int slot = actor->_255;
        if (apply && actor->_268 == 0) {
            d = setSlotJoints(slot, getActorJoint(actor, 0), getActorJoint(actor, 0));
            actor->pos.x = actor->pos.x + d.x;
            actor->pos.y = actor->pos.y + d.y;
            actor->pos.z = actor->pos.z + d.z;
            actor->_268 = 1;
        }
    }
}

// .text:0x8001B35C size:0x17C
int fn_8001B35C(int idx, int side) {
    Vec v;
    ModelActor* actor = lbl_8036E548.actors[idx];
    ModelSlot* slot;
    int jointIdx = 1;
    int steps = 0;
    int j;
    f32 y;
    f32 d;
    f32 t;

    if (actor == NULL) {
        return 0;
    }
    switch (side) {
    case 1:
        jointIdx = 2;
        break;
    case 0:
        jointIdx = 3;
        break;
    case 2:
        jointIdx = 1;
        break;
    }
    if (actor != NULL) {
        j = getActorJoint(actor, jointIdx);
        if (j == 0xFFFF) {
            y = 0.0f;
        } else {
            slot = &lbl_8036E548._0060->slots[actor->_255];
            fn_800B2C44(slot->node, j, &v);
            y = v.y;
            y += actor->pos.y;
        }
    }
    d = y - actor->pos.y;
    if (d < 0.0f && d >= -30.0f) {
        steps = 1;
        t = -0.5f;
        while (1) {
            if (d > t) {
                break;
            }
            t -= 0.5f;
            steps++;
        }
    } else if (d >= 0.5f && d < 30.0f) {
        t = 0.5f;
        while (1) {
            if (d < t) {
                break;
            }
            t += 0.5f;
            steps--;
        }
    }
    return steps;
}

// .text:0x8001B308 size:0x54
void fn_8001B308(s32 idx, BOOL on) {
    ModelActor* actor = lbl_8036E548.actors[idx];
    ModelSlot* slot;

    if (actor != NULL) {
        slot = &lbl_8036E548._0060->slots[actor->_255];
        if (!on) {
            slot->_68 = NULL;
        } else {
            slot->_68 = actor->_72;
        }
    }
}

// .text:0x8001B2D0 size:0x38
void fn_8001B2D0(void) {
    memcpy(lbl_8036C4FC, lbl_8036E548.actorData, sizeof(lbl_8036E548.actorData));
}

// .text:0x8001B224 size:0xAC
void fn_8001B224(void) {
}

// .text:0x8001B214 size:0x10
void fn_8001B214(void (*callback)(void)) {
    lbl_8036E548._308C = callback;
}

// .text:0x8001B200 size:0x14
void fn_8001B200(void) {
    lbl_8036E548._308C = NULL;
}

// .text:0x8001AF98 size:0x268
void fn_8001AF98(void) {
}

// .text:0x8001AB10 size:0x488
void fn_8001AB10(void) {
}

// .text:0x8001AAF0 size:0x20
void fn_8001AAF0(void) {
    fn_8003AC90();
}

// .text:0x8001AAA4 size:0x4C
void fn_8001AAA4(void) {
    ModelTask* task;

    task = fn_800B0A5C_insertQueue(challengeMapRelated, 0);
    task->_14 = 0;
    task->_0C->_10 = 0;
    lbl_8036E548._3082 = 0;
    lbl_803CBBF0 = 0;
}

// .text:0x8001A6B0 size:0x3F4
void challengeMapRelated(void) {
}

// .text:0x8001A3FC size:0x2B4
void fn_8001A3FC(void) {
}

// .text:0x8001A25C size:0x1A0
void fn_8001A25C(void) {
    LightPos* lights = lbl_80367318;
    ModelTask* task;
    int i;

    task = fn_800B0A5C_insertQueue(fn_80019C00, 0);
    task->_14 = 0;
    task->_0C->_10 = 0;
    for (i = 0; i < 4; i++) {
        fn_80023B90(&lbl_800F7478[g_d_GameSettings._54].lights[i], &lbl_80367318[i]);
    }
    fn_800BD2DC();
    if (lbl_800F7478[g_d_GameSettings._54].ambient.a != 0) {
        fn_800BD2CC(1, lbl_800F7478[g_d_GameSettings._54].ambient);
    }
    for (i = 0; i < 4; i++) {
        LITAlloc(&lbl_8036E548.lights[i]);
        LITInitAttn(lbl_8036E548.lights[i], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        LITInitPos(lbl_8036E548.lights[i], lights[i].pos.x, lights[i].pos.y, lights[i].pos.z);
        LITInitColor(lbl_8036E548.lights[i], lights[i].color);
    }
    if (lbl_8036E548._006C != NULL) {
        for (i = 0; i < lbl_8036E548._006C->count; i++) {
            fn_800BD548(&lbl_8036E548._006C->slots[i], 4, lbl_8036E548.lights[0], lbl_8036E548.lights[1], lbl_8036E548.lights[2], lbl_8036E548.lights[3]);
        }
    }
}

// .text:0x80019C00 size:0x65C
void fn_80019C00(void) {
}

// .text:0x80019A60 size:0x1A0
void fn_80019A60(void) {
    LightPos* lights = lbl_80367318;
    ModelTask* task;
    int i;

    task = fn_800B0A5C_insertQueue(fn_800196D8, 0);
    task->_14 = 0;
    task->_0C->_10 = 0;
    for (i = 0; i < 4; i++) {
        fn_80023B90(&lbl_800F7478[g_d_GameSettings._54].lights[i], &lbl_80367318[i]);
    }
    fn_800BD2DC();
    if (lbl_800F7478[g_d_GameSettings._54].ambient.a != 0) {
        fn_800BD2CC(1, lbl_800F7478[g_d_GameSettings._54].ambient);
    }
    for (i = 0; i < 4; i++) {
        LITAlloc(&lbl_8036E548.lights[i]);
        LITInitAttn(lbl_8036E548.lights[i], 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
        LITInitPos(lbl_8036E548.lights[i], lights[i].pos.x, lights[i].pos.y, lights[i].pos.z);
        LITInitColor(lbl_8036E548.lights[i], lights[i].color);
    }
    if (lbl_8036E548._006C != NULL) {
        for (i = 0; i < lbl_8036E548._006C->count; i++) {
            fn_800BD548(&lbl_8036E548._006C->slots[i], 4, lbl_8036E548.lights[0], lbl_8036E548.lights[1], lbl_8036E548.lights[2], lbl_8036E548.lights[3]);
        }
    }
}

// .text:0x800196D8 size:0x388
void fn_800196D8(void) {
}

// .text:0x80018DEC size:0x8EC
void fn_80018DEC(void) {
}

// .text:0x80018B74 size:0x278
void fn_80018B74(void) {
}

// .text:0x80018B38 size:0x3C
void fn_80018B38(void) {
    fn_800ACFB0(lbl_8036E548._2C88);
    lbl_8036E548._2D68 = -1;
}

// .text:0x800189E4 size:0x154
void fn_800189E4(void) {
    u32 max = 0;
    u32 size;
    u8* buf;
    u8* p;
    int i;

    for (i = 0; i < 54; i++) {
        size = lbl_803CB790[i * 19 + 15].size & 0x0FFFFFFF;
        if (max < size) {
            max = size;
        }
    }
    size = (max + 31) & ~31;
    lbl_8036E548.bufSize = size;
    buf = _OSAllocFromHeap(32, size * 4);
    p = buf + size;
    lbl_8036E548._2D10 = p;
    p += size;
    lbl_8036E548._2D24 = p;
    p += size;
    lbl_8036E548._2C88 = buf;
    lbl_8036E548._2CFC = buf;
    lbl_8036E548.actorData[0].anims[5] = NULL;
    lbl_8036E548.actorData[1].anims[5] = NULL;
    lbl_8036E548.actorData[2].anims[5] = NULL;
    lbl_8036E548._2D38 = p;
    lbl_8036E548.actorData[3].anims[5] = NULL;
}

// .text:0x800189B8 size:0x2C
void fn_800189B8(void) {
    fn_800ACFB0(lbl_8036E548._2C88);
}

// .text:0x800188C0 size:0xF8
void fn_800188C0(void) {
    ModelLoadReq* req = lbl_803CC1B8;

    switch (req->_14) {
    case 0:
        if (g_d_GameSettings.GameModeSelected == 6) {
            lbl_8036E548.files = ARAMTransfer(&lbl_800EE910[1], 0, 0, 0);
        } else {
            lbl_8036E548.files = ARAMTransfer(&lbl_800EE910[0], 0, 0, 0);
        }
        req->_14++;
        break;
    case 1:
        if ((s32)lbl_803C6CF8._715 == 1) {
            req->_14++;
        }
        break;
    case 2:
        lbl_8036E548._307B = 0;
        fn_800B0A14_removeQueue();
        break;
    }
}

// .text:0x80018270 size:0x650
void fn_80018270(void) {
}

// .text:0x80018024 size:0x24C
// 71.27%: the target keeps both a byte offset (i * 0x130) and an entry index (i * 19 + 1)
// for the size scan and reloads lbl_803CB790 each pass; the allocation tail is untested.
void fn_80018024(void) {
    u32 maxA = 0;
    u32 maxB = 0;
    u32 size;
    u32 sizeA;
    u32 sizeB;
    u8* p;
    s32 i;

    for (i = 0; i < 54; i++) {
        size = lbl_803CB790[i * 19].size & 0x0FFFFFFF;
        if (maxA < size) {
            maxA = size;
        }
        size = lbl_803CB790[i * 19 + 1].size & 0x0FFFFFFF;
        if (maxB < size) {
            maxB = size;
        }
    }
    sizeA = (maxA + 31) & ~31;
    lbl_8036E548._2D64 = sizeA;
    sizeB = (maxB + 31) & ~31;
    if (g_d_GameSettings.GameModeSelected == 6) {
        lbl_8036E548._2C8C = _OSAllocFromHeap(32, (sizeA + sizeB) * 4);
    } else {
        lbl_8036E548._2C8C = _OSAllocFromHeap(32, sizeA * 4);
    }
    if (g_d_GameSettings.GameModeSelected == 6) {
        p = lbl_8036E548._2C8C;
        for (i = 0; i < 4; i++) {
            lbl_8036E548.actorData[i]._08 = p;
            p += sizeA;
            lbl_8036E548.actorData[i]._2C = NULL;
            lbl_8036E548.actorData[i]._30 = NULL;
            lbl_8036E548.actorData[i]._0C = p;
            p += sizeB;
            lbl_8036E548.actorData[i + 4]._2C = NULL;
            lbl_8036E548.actorData[i + 4]._30 = NULL;
        }
    } else {
        p = lbl_8036E548._2C8C;
        for (i = 0; i < 4; i++) {
            lbl_8036E548.actorData[i]._08 = p;
            p += sizeA;
            lbl_8036E548.actorData[i]._2C = NULL;
            lbl_8036E548.actorData[i]._30 = NULL;
        }
    }
}

// .text:0x80017DBC size:0x268
void fn_80017DBC(void) {
}

// .text:0x80017D28 size:0x94
void fn_80017D28(void) {
}

// .text:0x80017814 size:0x514
void fn_80017814(void) {
}

// .text:0x800177B4 size:0x60
void fn_800177B4(void) {
    ModelLoadReq* req = lbl_803CC1B8;

    if (fn_8001758C(&req->_14, req->_1C, req->_16, req->_19, req->_1A, req->_1B, req->_15, req->_1D) != 0) {
        lbl_8036E548._2D77 = 2;
        fn_800B0A14_removeQueue();
    }
}

// .text:0x8001758C size:0x228
s32 fn_8001758C(u8* arg0, s32 idx, u8 arg2, u8 arg3, u8 arg4, s8 arg5, u8 arg6, u8 arg7) {
    return 0;
}

// .text:0x80017340 size:0x24C
// 95.23%: the target recomputes &actors[i + 9] each outer pass where this strength-reduces
// it, and keeps found[] at sp+8 (here sp+12).
BOOL fn_80017340(int idx) {
    ModelActor* actor = &lbl_8036E548.actorData[idx];
    int j;
    int i;
    BOOL found[4];
    ModelActor* other;
    int entry;
    if (lbl_8036E548._2D8D == 0) {
        found[0] = FALSE;
        found[1] = FALSE;
        found[2] = FALSE;
        found[3] = FALSE;
        for (i = 9; i < 13; i++) {
            for (j = 0; j < 4; j++) {
                other = lbl_8036E548.actors[i];
                if (other != NULL) {
                    if (actor->_252 == lbl_8036E548._2D89[j]) {
                        actor->anims[1] = lbl_8036E548._2CB0[j];
                        return TRUE;
                    }
                    if (other->_252 == lbl_8036E548._2D89[j]) {
                        found[j] = TRUE;
                        break;
                    }
                }
            }
        }
        for (j = 0; j < 4; j++) {
            if (!found[j]) {
                lbl_8036E548._2D89[j] = -1;
            }
        }
        for (j = 0; j < 4; j++) {
            if (lbl_8036E548._2D89[j] < 0) {
                break;
            }
        }
        lbl_8036E548._2D89[j] = actor->_252;
        actor->anims[1] = lbl_8036E548._2CB0[j];
        if (g_d_GameSettings.GameModeSelected == 2) {
            entry = actor->_252 * 19 + 11;
        } else {
            entry = actor->_252 * 19 + 3;
        }
        ARAMTransfer(&lbl_803CB790[entry], actor->anims[1], 0, 0);
        lbl_8036E548._2D8D = 1;
    } else if ((s32)lbl_803C6CF8._715 == 1) {
        ANIMGet(actor->anims[1]);
        return TRUE;
    }
    return FALSE;
}

// .text:0x80017098 size:0x2A8
BOOL fn_80017098(int team, int player, int arg2, int slot, int arg4, int arg5) {
    ModelLoadReq* req;
    ModelActor* actor;
    BOOL same;
    int i;
    int j;

    if (arg5 >= 0) {
        req = fn_800B0A5C_insertQueue(fn_800177B4, 0);
        i = slot;
    } else {
        for (i = 0; i < 13; i++) {
            same = FALSE;
            if (lbl_8036E548.actorData[i]._252 == inMemRoster[team][player]._24 && lbl_8036E548.actorData[i]._25A == inMemRoster[team][player]._26 &&
                lbl_8036E548.actorData[i]._25B == inMemRoster[team][player]._27 && lbl_8036E548.actorData[i]._257 == (s8)player) {
                same = TRUE;
            }
            if (lbl_8036E548.actorData[i]._256 == team && same && lbl_8036E548.actorData[i]._258 == arg2 && lbl_8036E548.actorData[i]._259 == arg4) {
                lbl_8036E548._2D77 = 0;
                lbl_8036E548._2D6A[i] = slot;
                lbl_8036E548._2D79 = i;
                actor = &lbl_8036E548.actorData[i];
                lbl_8036E548.actorData[i]._254 = slot;
                for (j = 0; j < 13; j++) {
                    if (lbl_8036E548.actors[j] == actor) {
                        lbl_8036E548.actors[j] = NULL;
                        break;
                    }
                }
                lbl_8036E548.actors[slot] = actor;
                return TRUE;
            }
        }
        req = fn_800B0A5C_insertQueue(fn_800177B4, 0);
        if (slot >= 9) {
            for (i = 9; i < 13; i++) {
                if (lbl_8036E548._2D6A[i] < 0) {
                    break;
                }
            }
        } else {
            for (i = 0; i < 13; i++) {
                if (lbl_8036E548._2D6A[i] < 0) {
                    break;
                }
            }
        }
    }
    req->_14 = 0;
    req->_1C = i;
    req->_19 = team;
    req->_1A = player;
    req->_1B = arg2;
    req->_15 = slot;
    req->_1D = arg4;
    if (arg5 < 0) {
        req->_16 = inMemRoster[team][player]._24;
    } else {
        req->_16 = arg5;
    }
    lbl_8036E548._2D6A[i] = slot;
    lbl_8036E548._2D77 = 1;
    lbl_8036E548._2D79 = i;
    return FALSE;
}

// .text:0x80016F7C size:0x11C
void fn_80016F7C(void) {
}

// .text:0x80016B60 size:0x41C
void fn_80016B60(void) {
}

// .text:0x80016710 size:0x450
void fn_80016710(void) {
}

// .text:0x80016344 size:0x3CC
void fn_80016344(void) {
}

// .text:0x8001594C size:0x9F8
void fn_8001594C(void) {
}

// .text:0x80015468 size:0x4E4
void fn_80015468(void) {
}

// .text:0x8001500C size:0x45C
void fn_8001500C(void) {
}

// .text:0x80014F40 size:0xCC
BOOL fn_80014F40(int id) {
    if (id < 0) {
        return TRUE;
    }
    if (lbl_8036E548._2D46 <= 1) {
        int idx = id * 19 + 1;
        if ((s8)lbl_803C6CF8._715 != 1) {
            lbl_8036E548._2D46 = 1;
            return FALSE;
        }
        ARAMTransfer(&lbl_803CB790[idx], lbl_8036E548._2D3C, 0, 0);
        lbl_8036E548._2D46 = 2;
    } else if ((s32)lbl_803C6CF8._715 == 1) {
        lbl_8036E548._2D44 = id;
        lbl_8036E548._2D46 = 0;
        return TRUE;
    }
    return FALSE;
}

// .text:0x80014E50 size:0xF0
BOOL fn_80014E50(int id) {
    if (id < 0) {
        return TRUE;
    }
    if (lbl_8036E548._2D5E <= 1) {
        int idx = id * 19;
        if ((s32)lbl_803C6CF8._715 != 1) {
            lbl_8036E548._2D5E = 1;
            return FALSE;
        }
        if (fn_8002204C(id, lbl_8036E548._2D54) == NULL) {
            ARAMTransfer(&lbl_803CB790[idx], lbl_8036E548._2D54, 0, 0);
        }
        lbl_8036E548._2D5E = 2;
    } else if (lbl_803716B8._1E8 == 0 && (s32)lbl_803C6CF8._715 == 1) {
        lbl_8036E548._2D5C = id;
        lbl_8036E548._2D5E = 0;
        return TRUE;
    }
    return FALSE;
}

// .text:0x80014D4C size:0x104
BOOL fn_80014D4C(int id) {
    int idx;

    if (id < 0) {
        return TRUE;
    }
    if (lbl_8036E548._2D50 == id) {
        return TRUE;
    }
    if (lbl_8036E548._2D52 <= 1) {
        if (g_d_GameSettings.GameModeSelected == 2) {
            idx = id * 19 + 10;
        } else {
            idx = id * 19 + 2;
        }
        if ((s32)lbl_803C6CF8._715 != 1) {
            lbl_8036E548._2D52 = 1;
            return FALSE;
        }
        ARAMTransfer(&lbl_803CB790[idx], lbl_8036E548._2D48, 0, 0);
        lbl_8036E548._2D52 = 2;
    } else if ((s32)lbl_803C6CF8._715 == 1) {
        lbl_8036E548._2D50 = id;
        lbl_8036E548._2D52 = 0;
        return TRUE;
    }
    return FALSE;
}

// .text:0x80014A18 size:0x334
void fn_80014A18(void) {
}

// .text:0x80014990 size:0x88
// 96.76%: the NULL-actor return is `bne` over a `b` in the target, one `beq` here.
void fn_80014990(s32 idx, void* file, void* hdr) {
    ModelActor* actor;
    ModelSub2C* sub;

    if (idx >= 0 && idx < 13) {
        actor = lbl_8036E548.actors[idx];
        if (actor == NULL) {
            return;
        }
        sub = &lbl_80118220[idx];
        actor->_2C = sub;
        sub->_60 = actor->_252;
        sub->_61 = actor->_254;
        sub->state.hdr = hdr;
        sub->state.file = file;
        fn_80025FFC(file, &sub->state);
    }
}

// .text:0x800145F8 size:0x398
void fn_800145F8(void) {
}

// .text:0x80014204 size:0x3F4
void fn_80014204(void) {
}

// .text:0x80013680 size:0xB84
void fn_80013680(void) {
}

// .text:0x80012B90 size:0xAF0
void fn_80012B90(void) {
}

// .text:0x800127F8 size:0x398
void LoadModel(void) {
}

// .text:0x800126EC size:0x10C
void fn_800126EC(ModelSub2C* sub, void* tex, u8* idx) {
    void* layout;
    void* geo;
    ModelSlot* slot;

    slot = &lbl_8036E548._013C->slots[sub->_60];
    layout = sub->files[idx[0]];
    geo = sub->files[idx[1]];
    LoadActorLayout(layout);
    convertGeometryAndSknHeader(geo, NULL);
    haveActLayoutPointToGeoHeader(layout, geo);
    fn_800BD190(geo, tex);
    fn_800238E0(lbl_8036E548._013C, sub->_60, sub->_60, layout);
    if (sub->files[2] != NULL) {
        fn_80025DDC(sub->files[idx[2]]);
        fn_80025C58(sub->files[idx[2]], (struct Model*)slot);
    }
    sub->state.hdr = sub->files[idx[3]];
    fn_80025FFC(sub->files[idx[2]], &sub->state);
}

// .text:0x80011CA8 size:0xA44
void fn_80011CA8(void) {
}

// .text:0x80011BE4 size:0xC4
void fn_80011BE4(s32 idx) {
    ModelSub2C* sub;
    ModelPose* pose;
    int i;

    if (lbl_8036E548.actors[idx] != NULL) {
        sub = lbl_8036E548.actors[idx]->_2C;
        if (sub != NULL) {
            sub->_61 = -1;
            sub->state.current = -2;
            lbl_8036E548.actors[idx]->_2C = NULL;
        }
        pose = lbl_8036E548.actors[idx]->_30;
        if (pose != NULL) {
            pose->_D1 = pose->_D0;
            pose->_D0 = -1;
            pose->state.current = -2;
            pose->state2.current = -2;
            lbl_8036E548.actors[idx]->_30 = NULL;
        }
        lbl_8036E548.actors[idx]->_25C = 0;
    }
    lbl_8036E548.actors[idx] = NULL;
    for (i = 0; i < 13; i++) {
        if (lbl_8036E548._2D6A[i] == idx) {
            lbl_8036E548._2D6A[i] = -1;
        }
    }
}

// .text:0x80011B64 size:0x80
void fn_80011B64(s32 idx) {
    ModelSub2C* sub;
    ModelPose* pose;

    if (lbl_8036E548.actors[idx] != NULL) {
        sub = lbl_8036E548.actors[idx]->_2C;
        if (sub != NULL) {
            sub->_61 = -1;
            sub->state.current = -2;
            lbl_8036E548.actors[idx]->_2C = NULL;
        }
        pose = lbl_8036E548.actors[idx]->_30;
        if (pose != NULL) {
            pose->_D1 = pose->_D0;
            pose->_D0 = -1;
            pose->state.current = -2;
            pose->state2.current = -2;
            lbl_8036E548.actors[idx]->_30 = NULL;
        }
    }
}

// .text:0x80011A60 size:0x104
void fn_80011A60(void) {
    ModelSub2C* sub;
    ModelPose* pose;
    int i;
    int j;
    int idx;

    for (i = 0; i < 4; i++) {
        idx = i + 9;
        if (lbl_8036E548.actors[idx] != NULL) {
            sub = lbl_8036E548.actors[idx]->_2C;
            if (sub != NULL && lbl_8036E548.actors[idx]->_254 == idx) {
                sub->_61 = -1;
                sub->state.current = -2;
                lbl_8036E548.actors[idx]->_2C = NULL;
            }
        }
        if (lbl_8036E548.actors[idx] != NULL) {
            pose = lbl_8036E548.actors[idx]->_30;
            if (pose != NULL && lbl_8036E548.actors[idx]->_254 == idx) {
                pose->_D1 = pose->_D0;
                pose->_D0 = -1;
                pose->state.current = -2;
                pose->state2.current = -2;
                lbl_8036E548.actors[idx]->_30 = NULL;
            }
        }
        if (lbl_8036E548.actors[idx] != NULL) {
            lbl_8036E548.actors[idx]->_25C = 0;
            lbl_8036E548.actors[idx] = NULL;
        }
        for (j = 0; j < 13; j++) {
            if (lbl_8036E548._2D6A[j] == idx) {
                lbl_8036E548._2D6A[j] = -1;
            }
        }
    }
}

// .text:0x8001196C size:0xF4
// 99.18%: registers only; the base pointer copies and the pose pointer swap r8/r9.
void fn_8001196C(void) {
    ModelSub2C* sub;
    ModelPose* pose;
    int i;
    int j;

    for (i = 0; i < 9; i++) {
        if (lbl_8036E548.actors[i] != NULL) {
            sub = lbl_8036E548.actors[i]->_2C;
            if (sub != NULL && lbl_8036E548.actors[i]->_254 == i) {
                sub->_61 = -1;
                sub->state.current = -2;
                lbl_8036E548.actors[i]->_2C = NULL;
            }
        }
        if (lbl_8036E548.actors[i] != NULL) {
            pose = lbl_8036E548.actors[i]->_30;
            if (pose != NULL && lbl_8036E548.actors[i]->_254 == i) {
                pose->_D1 = pose->_D0;
                pose->_D0 = -1;
                pose->state.current = -2;
                pose->state2.current = -2;
                lbl_8036E548.actors[i]->_30 = NULL;
            }
        }
        lbl_8036E548.actors[i]->_25C = 0;
        lbl_8036E548.actors[i] = NULL;
        for (j = 0; j < 13; j++) {
            if (lbl_8036E548._2D6A[j] == i) {
                lbl_8036E548._2D6A[j] = -1;
            }
        }
    }
}

// .text:0x800118AC size:0xC0
MtxPtr fn_800118AC(Mtx src, Mtx dst) {
    Mtx scale = { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0714285f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } };

    PSMTXConcat(scale, src, dst);
    dst[0][3] = 0.0f;
    dst[1][3] = 0.0f;
    dst[2][3] = 0.0f;
    PSMTXInverse(dst, dst);
    return dst;
}

// .text:0x800117CC size:0xE0
void fn_800117CC(Mtx pos, Mtx src, Mtx dst) {
    Mtx m;
    Mtx scale = { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0714285f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } };

    PSMTXConcat(scale, src, m);
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    PSMTXInverse(m, m);
    m[0][3] = pos[0][3];
    m[1][3] = pos[1][3];
    m[2][3] = pos[2][3];
    PSMTXCopy(m, dst);
}

// .text:0x800116DC size:0xF0
void fn_800116DC(ModelHandle* model, Mtx src, u16 joint) {
    Mtx m;
    Mtx scale = { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0714285f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } };
    MtxPtr dst;

    PSMTXConcat(scale, src, m);
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    PSMTXInverse(m, m);
    dst = model->data->joints[joint]->mtx;
    m[0][3] = dst[0][3];
    m[1][3] = dst[1][3];
    m[2][3] = dst[2][3];
    PSMTXCopy(m, dst);
}

// .text:0x80011640 size:0x9C
void fn_80011640(Mtx src, Mtx dst) {
    Mtx scale = { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 0.93333334f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } };

    PSMTXConcat(scale, src, dst);
}

// .text:0x80011604 size:0x3C
void fn_80011604(s8 idx, s32 value) {
    ModelActor* actor;

    if (idx < 0 || idx >= 13) {
        return;
    }
    actor = lbl_8036E548.actors[idx];
    if (actor != NULL) {
        actor->_5C = value;
    }
}

// .text:0x800115C8 size:0x3C
void fn_800115C8(s8 idx) {
    ModelActor* actor;

    if (idx >= 0 && idx < 13) {
        actor = lbl_8036E548.actors[idx];
        if (actor != NULL) {
            actor->_5C = 0;
        }
    }
}

// .text:0x80011578 size:0x50
void fn_80011578(void) {
    int i;

    for (i = 0; i < 13; i++) {
        fn_800115C8(i);
    }
}

// .text:0x80011570 size:0x8
ModelActor* fn_80011570(void) {
    return lbl_803CBC18;
}

// .text:0x80011468 size:0x108
void fn_80011468(void) {
    ModelActor* actor;
    ModelSlot* slot;
    int i;

    for (i = 0; i < 13; i++) {
        actor = lbl_8036E548.actors[i];
        if (actor != NULL) {
            slot = &lbl_8036E548._0060->slots[actor->_255];
            switch (actor->_252) {
            case 19:
                fn_8004B6EC(actor, slot);
                break;
            case 40:
            case 41:
                fn_8004B7F4(actor);
                break;
            case 38:
                slot->node->_99 = 1;
            case 18:
                fn_8004BAEC(actor, slot);
                break;
            case 14:
            case 37:
                fn_8005240C(actor, slot);
                break;
            case 6:
            case 10:
            case 12:
            case 24:
            case 25:
            case 26:
            case 42:
                slot->node->_99 = 1;
                break;
            case 20:
            case 43:
                if (actor->_62 == 0x40) {
                    slot->node->_99 = 0;
                } else {
                    slot->node->_99 = 1;
                }
                break;
            }
        }
    }
}

// .text:0x80011358 size:0x110
void fn_80011358(int idx, int part) {
    ModelActor* actor;
    ModelSlot* slot;
    ModelNode* src;
    u16 joint;
    u16 n;
    int k;

    if (idx < 0 || idx >= 13) {
        return;
    }
    actor = lbl_8036E548.actors[idx];
    if (actor == NULL || lbl_8036E548._0060 == NULL || lbl_8036E548._0064 == NULL) {
        return;
    }
    joint = actor->joints[36];
    if (joint == 0xFFFF) {
        return;
    }
    if (part < 0 || part >= 5) {
        part = 4;
    }
    slot = &lbl_8036E548._0060->slots[actor->_255];
    if (part == 4) {
        fn_800B2BA8(slot->node, joint, NULL, 0);
        return;
    }
    src = lbl_8036E548._0064->slots[part + 21].node;
    for (k = 0, n = src->numBones; k < n; k++) {
        if (src->bones[k]->dispObj != NULL) {
            fn_800B2BA8(slot->node, joint, src, k);
            return;
        }
    }
}

// .text:0x800111FC size:0x15C
// 66.30%: waits on fn_8001BA44, whose empty stub is inlined here; the target calls it
// with bl. The rest follows the target line by line.
ModelActor* fn_800111FC(ModelActor* actor, BOOL alt) {
    ModelActor* target;
    int slot;

    if (g_d_GameSettings.GameModeSelected != 6) {
        return actor;
    }
    slot = actor->_255 % 4;
    lbl_8036E548.actorData[slot + 4]._25D = 0;
    lbl_8036E548.actorData[slot]._25D = 0;
    target = &lbl_8036E548.actorData[slot + (alt ? 4 : 0)];
    lbl_8036E548.actors[slot] = target;
    if (target->_255 != actor->_255) {
        fn_8001BA44(slot, actor->_62, actor->_25F, actor->_262, 0, actor->_265, actor->_269);
        target->_64 = actor->_64;
        target->_6C = actor->_6C;
        target->_25E = actor->_25E;
        target->_260 = actor->_260;
        target->_263 = actor->_263;
        target->_266 = actor->_266;
        target->_26A = actor->_26A;
        target->_26D = actor->_26D;
        target->_66 = actor->_66;
        target->_6E = actor->_6E;
        target->_261 = actor->_261;
        target->_264 = actor->_264;
        target->_267 = actor->_267;
        target->_26B = actor->_26B;
        target->_26E = actor->_26E;
    }
    return target;
}

// .text:0x800111D8 size:0x24
ModelSlot* fn_800111D8(ModelActor* actor) {
    return &lbl_8036E548._0060->slots[actor->_255];
}
