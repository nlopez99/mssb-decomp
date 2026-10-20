#include "static/model.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "C3/control.h"
#include "C3/geoPalette.h"
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
    /* 0x0C */ u8 r;
    /* 0x0D */ u8 g;
    /* 0x0E */ u8 b;
} LightPos;

typedef struct _VecXYZ {
    f32 x, y, z;
} VecXYZ;

// STRUCTS BEGIN
typedef struct JointPair {
    /* 0x0000 */ u16 a;
    /* 0x0002 */ u16 b;
} JointPair; // size: 0x4

typedef struct ModelEntry28 {
    /* 0x0000 */ u8 _0000[0x4 - 0x0];
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
    /* 0x0000 */ u8 _0000[0x14 - 0x0];
    /* 0x0014 */ struct DODisplayObj* dispObj;
    /* 0x0018 */ u8 _0018[0x64 - 0x18];
    /* 0x0064 */ MtxPtr skinMtx;
    /* 0x0068 */ MtxPtr skinInvMtx;
    /* 0x006C */ u8 _006C[0x74 - 0x6C];
    /* 0x0074 */ struct ModelNode* child;
    /* 0x0078 */ u8 _0078[0x7C - 0x78];
    /* 0x007C */ void* _7C;
    /* 0x0080 */ u16 joint;
    /* 0x0082 */ u8 _0082[0x98 - 0x82];
    /* 0x0098 */ u8 flags;
    /* 0x0099 */ u8 _0099[0xEC - 0x99];
    /* 0x00EC */ MtxPtr mtx;
    /* 0x00F0 */ u8 _00F0[0x100 - 0xF0];
    /* 0x0100 */ struct ModelNode* next;
} ModelNode; // size: 0x104

typedef struct LightSet {
    /* 0x0000 */ LightDesc lights[4];
    /* 0x0028 */ u8 _0028[0x2C - 0x28];
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

typedef struct ModelObj {
    /* 0x0000 */ u8 _0000[0x44 - 0x0];
    /* 0x0044 */ Control ctrl;
    /* 0x0088 */ u8 _0088[0x90 - 0x88];
} ModelObj; // size: 0x90

typedef struct AnimState {
    /* 0x0000 */ void* hdr;
    /* 0x0004 */ u8 _0004[0x2C - 0x4];
    /* 0x002C */ void* file;
    /* 0x0030 */ u8 _0030[0x58 - 0x30];
    /* 0x0058 */ s8 current;
    /* 0x0059 */ u8 _0059[0x5C - 0x59];
} AnimState; // size: 0x5C

typedef struct ModelSub2C {
    /* 0x0000 */ u8 _0000[0x4 - 0x0];
    /* 0x0004 */ AnimState state;
    /* 0x0060 */ s8 _60;
    /* 0x0061 */ s8 _61;
    /* 0x0062 */ u8 _0062[0x64 - 0x62];
} ModelSub2C; // size: 0x64

typedef struct ModelPose {
    /* 0x0000 */ u8 _0000[0x4 - 0x0];
    /* 0x0004 */ AnimState state;
    /* 0x0060 */ u8 _0060[0x68 - 0x60];
    /* 0x0068 */ AnimState state2;
    /* 0x00C4 */ u8 _00C4[0xD0 - 0xC4];
    /* 0x00D0 */ s8 _D0;
    /* 0x00D1 */ s8 _D1;
    /* 0x00D2 */ u8 _00D2[0xD4 - 0xD2];
} ModelPose; // size: 0xD4

typedef struct ModelActor {
    /* 0x0000 */ u8 _0000[0x2C - 0x0];
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
    /* 0x0256 */ u8 _0256[0x25C - 0x256];
    /* 0x025C */ s8 _25C;
    /* 0x025D */ s8 _25D;
    /* 0x025E */ s8 _25E;
    /* 0x025F */ s8 _25F;
    /* 0x0260 */ s8 _260;
    /* 0x0261 */ s8 _261;
    /* 0x0262 */ s8 _262;
    /* 0x0263 */ s8 _263;
    /* 0x0264 */ s8 _264;
    /* 0x0265 */ u8 _0265[0x266 - 0x265];
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
    /* 0x0275 */ u8 _0275[0x278 - 0x275];
    /* 0x0278 */ s8 _278;
    /* 0x0279 */ u8 _0279[0x27C - 0x279];
} ModelActor; // size: 0x27C

typedef struct ModelSlot {
    /* 0x0000 */ ModelNode* node;
    /* 0x0004 */ u8 _0004[0x64 - 0x4];
    /* 0x0064 */ u16 _64;
    /* 0x0066 */ u16 _66;
    /* 0x0068 */ u16* _68;
    /* 0x006C */ u8 _6C;
    /* 0x006D */ u8 _006D[0x90 - 0x6D];
} ModelSlot; // size: 0x90

typedef struct ModelTable {
    /* 0x0000 */ u16 count;
    /* 0x0002 */ u8 _0002[0x34 - 0x2];
    /* 0x0034 */ ModelSlot slots[1];
} ModelTable; // size: 0xC4

typedef struct ModelWork {
    /* 0x0000 */ u8 _0000[0x60 - 0x0];
    /* 0x0060 */ ModelTable* _0060;
    /* 0x0064 */ ModelObj* _0064;
    /* 0x0068 */ ModelObj* _0068;
    /* 0x006C */ u8 _006C[0x140 - 0x6C];
    /* 0x0140 */ ModelPose poses[13];
    /* 0x0C04 */ ModelActor actorData[13];
    /* 0x2C50 */ ModelActor* actors[13];
    /* 0x2C84 */ u8 _2C84[0x2C88 - 0x2C84];
    /* 0x2C88 */ void* _2C88;
    /* 0x2C8C */ u8 _2C8C[0x2D3C - 0x2C8C];
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
    /* 0x2D5F */ u8 _2D5F[0x2D68 - 0x2D5F];
    /* 0x2D68 */ s16 _2D68;
    /* 0x2D6A */ s8 _2D6A[13];
    /* 0x2D77 */ s8 _2D77;
    /* 0x2D78 */ u8 _2D78[0x2D90 - 0x2D78];
    /* 0x2D90 */ ModelEntry28* _2D90;
    /* 0x2D94 */ u8 _2D94[0x3078 - 0x2D94];
    /* 0x3078 */ s16 _3078;
    /* 0x307A */ u8 _307A;
    /* 0x307B */ u8 _307B[0x3082 - 0x307B];
    /* 0x3082 */ s8 _3082;
    /* 0x3083 */ u8 _3083[0x308C - 0x3083];
    /* 0x308C */ void (*_308C)(void);
    /* 0x3090 */ u8 _3090[0x3154 - 0x3090];
} ModelWork; // size: 0x3154

// STRUCTS END

extern ModelWork lbl_8036E548;
extern u8 lbl_8036C4FC[0x204C];
extern u8 lbl_803CBBC0;
extern s32 lbl_803CBC18;
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
void fn_800B2C10(ModelNode* node, u16 joint, Vec* out);
void fn_800B2C44(ModelNode* node, u16 joint, Vec* out);

extern u8 lbl_800F1D78[][0x10];
extern u8 lbl_800F71D8[];
extern u8 lbl_800F5D98[];

u8 (*lbl_803CB790)[0x10] = lbl_800F1D78;
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
u32 lbl_800EE910[8] = {
    0x0000040B, 0x40093FF8, 0x0E581000, 0x0005F484, 0x0000040B, 0x40095BB8, 0x0E5E0800, 0x0006053C,
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
void fn_8001F8A4(void) {
}

// .text:0x8001F5E8 size:0x2BC
void fn_8001F5E8(void) {
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

// .text:0x8001E784 size:0x9E8
void fn_8001E784(void) {
}

// .text:0x8001E488 size:0x2FC
void fn_8001E488(void) {
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
void fn_8001E0D8(void) {
}

// .text:0x8001DEA4 size:0x234
void fn_8001DEA4(void) {
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
void fn_8001DB74(void) {
}

// .text:0x8001D2D4 size:0x8A0
void fn_8001D2D4(void) {
}

// .text:0x8001D180 size:0x154
void fn_8001D180(void) {
}

// .text:0x8001D148 size:0x38
void fn_8001D148(s32 idx, f32 x, f32 y, f32 z) {
    CTRLSetScale(&lbl_8036E548._0064[idx].ctrl, x, y, z);
}

// .text:0x8001D110 size:0x38
void fn_8001D110(s32 idx, f32 x, f32 y, f32 z) {
    CTRLSetScale(&lbl_8036E548._0068[idx].ctrl, x, y, z);
}

// .text:0x8001D0D0 size:0x40
void fn_8001D0D0(s32 idx, f32 scale) {
    CTRLSetScale(&lbl_8036E548._0068[idx].ctrl, scale, scale, scale);
}

// .text:0x8001D074 size:0x5C
void fn_8001D074(void) {
}

// .text:0x8001CE74 size:0x200
void fn_8001CE74(void) {
}

// .text:0x8001CCC8 size:0x1AC
void fn_8001CCC8(void) {
}

// .text:0x8001CBD4 size:0xF4
void fn_8001CBD4(void) {
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
void fn_8001C920(void) {
}

// .text:0x8001C67C size:0x2A4
int fn_8001C67C_animation(int, int) {
}

// .text:0x8001C588 size:0xF4
void fn_8001C588(void) {
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
void fn_8001BA44(void) {
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
void fn_8001B35C(void) {
}

// .text:0x8001B308 size:0x54
void fn_8001B308(void) {
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
}

// .text:0x80019C00 size:0x65C
void fn_80019C00(void) {
}

// .text:0x80019A60 size:0x1A0
void fn_80019A60(void) {
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
}

// .text:0x800189B8 size:0x2C
void fn_800189B8(void) {
    fn_800ACFB0(lbl_8036E548._2C88);
}

// .text:0x800188C0 size:0xF8
void fn_800188C0(void) {
}

// .text:0x80018270 size:0x650
void fn_80018270(void) {
}

// .text:0x80018024 size:0x24C
void fn_80018024(void) {
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
void fn_80017340(void) {
}

// .text:0x80017098 size:0x2A8
void fn_80017098(void) {
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
        ARAMTransfer(lbl_803CB790[idx], lbl_8036E548._2D3C, 0, 0);
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
            ARAMTransfer(lbl_803CB790[idx], lbl_8036E548._2D54, 0, 0);
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
        ARAMTransfer(lbl_803CB790[idx], lbl_8036E548._2D48, 0, 0);
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
void fn_800126EC(void) {
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
s32 fn_80011570(void) {
    return lbl_803CBC18;
}
