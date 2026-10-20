#include "static/physics.h"
#include "Dolphin/mtx.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"
#include "math.h"

// Rigid-body and rope simulation: a stick swung about one end, and a chain of nodes

typedef struct RigidBody {
    /* 0x000 */ Vec tip;
    /* 0x00C */ Vec pivot;
    /* 0x018 */ Vec arm;
    /* 0x024 */ f32 mass;
    /* 0x028 */ f32 invMass;
    /* 0x02C */ f32 radius;
    /* 0x030 */ Vec inertia;
    /* 0x03C */ Vec invInertia;
    /* 0x048 */ f32 dt;
    /* 0x04C */ s32 steps;
    /* 0x050 */ f32 _50;
    /* 0x054 */ f32 _54;
    /* 0x058 */ Mtx world;
    /* 0x088 */ Mtx rot;
    /* 0x0B8 */ Mtx invRot;
    /* 0x0E8 */ Vec pos;
    /* 0x0F4 */ Quaternion quat;
    /* 0x104 */ Vec _104;
    /* 0x110 */ Vec force;
    /* 0x11C */ Vec vel;
    /* 0x128 */ Vec localVel;
    /* 0x134 */ Vec torque;
    /* 0x140 */ Vec angVel;
    /* 0x14C */ u8 _14C;
    /* 0x14D */ u8 _14D;
    /* 0x14E */ s8 axis;
} RigidBody;

typedef struct RopeParams {
    /* 0x00 */ f32 _00;
    /* 0x04 */ f32 _04;
    /* 0x08 */ f32 _08;
    /* 0x0C */ f32 _0C;
    /* 0x10 */ f32 _10;
    /* 0x14 */ f32 _14;
    /* 0x18 */ f32 dt;
    /* 0x1C */ f32 dt2;
    /* 0x20 */ s32 steps;
    /* 0x24 */ f32 _24;
} RopeParams;

typedef struct PhysActor {
    /* 0x000 */ u8 _000[0x162];
    /* 0x162 */ u16 bones[1];
    /* 0x164 */ u8 _164[0x255 - 0x164];
    /* 0x255 */ s8 slot;
    /* 0x256 */ u8 _256[0x27C - 0x256];
} PhysActor; // size: 0x27C

typedef struct PhysBone {
    /* 0x00 */ u8 _00[0xEC];
    /* 0xEC */ MtxPtr mtx;
} PhysBone;

typedef struct PhysModel {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ PhysBone** bones;
} PhysModel;

typedef struct PhysSlot {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ PhysModel* model;
    /* 0x38 */ u8 _38[0x90 - 0x38];
} PhysSlot; // size: 0x90

extern struct {
    /* 0x0000 */ u8 _0000[0x60];
    /* 0x0060 */ PhysSlot* slots;
    /* 0x0064 */ u8 _0064[0xC38 - 0x64];
    /* 0x0C38 */ Vec _C38;
    /* 0x0C44 */ u8 _0C44[0x2C50 - 0xC44];
    /* 0x2C50 */ PhysActor* fielders[13];
} lbl_8036E548;

typedef struct PhysTask {
    /* 0x00 */ void (*func)(void);
    /* 0x04 */ u8 _04[0x14 - 0x4];
    /* 0x14 */ void (*_14)(s32);
    /* 0x18 */ struct RigidBody* body;
    /* 0x1C */ void* anim;
    /* 0x20 */ Vec pos;
    /* 0x2C */ Quaternion rot;
    /* 0x3C */ u16 bone;
    /* 0x3E */ u8 fielder;
} PhysTask;

extern PhysTask* lbl_803CC1B8;

extern void fn_800B0A14_removeQueue(void);
extern void* fn_800B0A5C_insertQueue(void (*func)(void), u16 priority);
extern u32 fn_80024D2C(void* anim);
extern BOOL getAnimRelatedCoordinates(int, int, Vec*);

typedef struct PhysState {
    /* 0x00 */ Mtx mtx;
    /* 0x30 */ Vec _30;
    /* 0x3C */ Vec _3C;
    /* 0x48 */ Vec _48;
    /* 0x54 */ Vec _54;
    /* 0x60 */ Vec _60;
    /* 0x6C */ Vec _6C;
    /* 0x78 */ s32 state;
    /* 0x7C */ s32 _7C;
    /* 0x80 */ s32 _80;
    /* 0x84 */ s32 _84;
} PhysState; // size: 0x88

static Vec lbl_800F79A0[2] = { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } };
static PhysState lbl_800F79B8 = {
    { { 1.0f, 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f } },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, -0.89597f, 0.0f },
    { 0.0f, -0.89597f, 0.0f },
    { 0.0f, 0.89597f, 0.0f },
    { 0.23933218f, 0.02711064f, 0.23933218f },
    0,
    25,
    36,
    0,
};

s16 lbl_803CB818 = -1;
f32 lbl_803CB81C = 1.0f;
s32 lbl_803CB820 = -1;
f32 lbl_803CB824 = 0.25f;

u8 lbl_803CBCA2;
u8 lbl_803CBCA1;
u8 lbl_803CBCA0;

// .text:0x80039A4C size:0x5C
void fn_80039A4C(void)
{
    lbl_800F79B8.state = -1;
    lbl_803CBCA2 = 0;
    memset(&lbl_800F79A0, 0, sizeof(Vec));
    lbl_803CB818 = -1;
    lbl_803CB820 = -1;
    lbl_803CBCA1 = 0;
}

// .text:0x80039310 size:0x73C
void fn_80039310(void)
{
}

// .text:0x80038F08 size:0x408
void fn_80038F08(void)
{
}

// .text:0x80038EC4 size:0x44
void fn_80038EC4(void)
{
}

// .text:0x80038E2C size:0x98
void fn_80038E2C(RopeParams* params)
{
    params->_00 = 0.8f;
    params->_04 = 0.5f;
    params->_08 = 100.0f;
    params->_0C = 5.0f;
    params->_10 = 1.5f;
    params->_14 = 0.001f;
    params->steps = 8;
    params->dt = (1.0f / params->steps) / 60.0f;
    params->dt2 = params->dt * params->dt;
    params->_24 = 1.0f / (2.0f * params->dt);
}

// .text:0x80038CD0 size:0x15C
void fn_80038CD0(void)
{
}

// .text:0x80038B48 size:0x188
void fn_80038B48(void)
{
}

// .text:0x800387B0 size:0x398
void fn_800387B0(void)
{
}

// .text:0x800385F0 size:0x1C0
void fn_800385F0(RigidBody* body, f32 length, f32 center, f32 radius, f32 mass)
{
    f32 inertia;
    f32 inv;

    body->pivot.x = 0.0f;
    body->pivot.y = -length * center;
    body->pivot.z = 0.0f;
    body->tip.x = 0.0f;
    body->tip.y = length + body->pivot.y;
    body->tip.z = 0.0f;
    PSVECSubtract(&body->tip, &body->pivot, &body->arm);
    body->mass = mass;
    body->invMass = 1.0f / mass;
    inertia = mass * ((radius * radius / 4.0f) + ((length * length) / 12.0f));
    body->radius = radius;
    body->inertia.z = inertia;
    body->inertia.x = inertia;
    body->inertia.y = radius * (mass * radius) / 2.0f;
    inv = 1.0f / body->inertia.x;
    body->invInertia.z = inv;
    body->invInertia.x = inv;
    body->invInertia.y = 1.0f / body->inertia.y;
    body->steps = 1;
    body->dt = (1.0f / 60.0f) / body->steps;
    body->_50 = 0.0f;
    body->_54 = 0.5f;
    PSMTXIdentity(body->rot);
    PSMTXIdentity(body->world);
    body->pos.z = 0.0f;
    body->pos.y = 0.0f;
    body->pos.x = 0.0f;
    body->quat.z = 0.0f;
    body->quat.y = 0.0f;
    body->quat.x = 0.0f;
    body->quat.w = 1.0f;
    body->force.z = 0.0f;
    body->force.y = 0.0f;
    body->force.x = 0.0f;
    body->vel.z = 0.0f;
    body->vel.y = 0.0f;
    body->vel.x = 0.0f;
    body->localVel.z = 0.0f;
    body->localVel.y = 0.0f;
    body->localVel.x = 0.0f;
    body->torque.z = 0.0f;
    body->torque.y = 0.0f;
    body->torque.x = 0.0f;
    body->angVel.z = 0.0f;
    body->angVel.y = 0.0f;
    body->angVel.x = 0.0f;
    body->_14D = 0;
    body->_14C = 0;
}

// .text:0x80038418 size:0x1D8
void fn_80038418(RigidBody* body, Vec* pos, Quaternion* rot, Vec* prevPos, Quaternion* prevRot)
{
    Mtx m2;
    Mtx m1;
    Vec v;
    Quaternion q;
    f32 angle;

    v.x = -body->pivot.x;
    v.y = -body->pivot.y;
    v.z = -body->pivot.z;
    PSMTXQuat(body->rot, rot);
    PSMTXInverse(body->rot, body->invRot);
    PSMTXTransApply(body->rot, body->world, pos->x, pos->y, pos->z);
    PSMTXMultVec(body->world, &v, &body->pos);
    memcpy(&body->quat, rot, sizeof(Quaternion));
    PSMTXQuat(m1, prevRot);
    PSMTXTransApply(m1, m2, prevPos->x, prevPos->y, prevPos->z);
    PSMTXMultVec(m2, &v, &v);
    PSVECSubtract(&body->pos, &v, &v);
    PSVECScale(&v, 60.0f, &body->vel);
    PSMTXMultVec(body->invRot, &body->vel, &body->localVel);
    memset(&body->vel, 0, sizeof(Vec));
    memset(&body->localVel, 0, sizeof(Vec));
    PSMTXQuat(m2, rot);
    PSMTXQuat(m1, prevRot);
    PSMTXInverse(m1, m1);
    PSMTXConcat(m2, m1, m2);
    C_QUATMtx(&q, m2);
    q.w = acos(q.w);
    angle = 60.0f * (2.0f * q.w);
    q.w = sin(q.w);
    if (q.w) {
        PSVECScale((Vec*)&q, angle / q.w, &body->angVel);
        return;
    }
    body->angVel.x = angle;
    body->angVel.y = 0.0f;
    body->angVel.z = 0.0f;
}

// .text:0x800383BC size:0x5C
MtxPtr fn_800383BC(RigidBody* body)
{
    PSMTXQuat(body->rot, &body->quat);
    PSMTXInverse(body->rot, body->invRot);
    PSMTXTransApply(body->rot, body->world, body->pos.x, body->pos.y, body->pos.z);
    return body->world;
}

// .text:0x8003819C size:0x220
void fn_8003819C(void)
{
}

// .text:0x80037BAC size:0x5F0
void fn_80037BAC(void)
{
}

// .text:0x80037B18 size:0x94
void fn_80037B18(RigidBody* body, Vec* force, f32 scale)
{
    Vec local;
    Vec arm;
    Vec torque;

    PSVECScale(&body->arm, 1.0f, &arm);
    PSVECAdd(&arm, &body->pivot, &arm);
    PSMTXMultVec(body->invRot, force, &local);
    PSVECAdd(&body->force, &local, &body->force);
    PSVECCrossProduct(&arm, &local, &torque);
    PSVECAdd(&body->torque, &torque, &body->torque);
}

// .text:0x80037AA0 size:0x78
void fn_80037AA0(RigidBody* body, s32 fielder, void (*callback)(s32), u16 bone, void* anim)
{
    PhysTask* task;

    if (lbl_8036E548.fielders[fielder] != NULL) {
        task = fn_800B0A5C_insertQueue(fn_80037984, 0x6001);
        task->body = body;
        task->fielder = fielder;
        task->bone = bone;
        task->anim = anim;
        task->_14 = callback;
    }
}

// .text:0x80037984 size:0x11C
void fn_80037984(void)
{
    Mtx m;
    Vec pos;
    Quaternion q;
    PhysTask* task = lbl_803CC1B8;
    PhysActor* actor = lbl_8036E548.fielders[task->fielder];
    u16 bone = actor != NULL ? actor->bones[task->bone] : 0xFFFF;

    PSMTXCopy(lbl_8036E548.slots[actor->slot].model->bones[bone]->mtx, m);
    m[2][3] = 0.0f;
    m[1][3] = 0.0f;
    m[0][3] = 0.0f;
    C_QUATMtx(&q, m);
    getAnimRelatedCoordinates(task->fielder, task->bone, &pos);
    if (fn_80024D2C(task->anim) & 0x10000000) {
        fn_80038418(task->body, &pos, &q, &task->pos, &task->rot);
        lbl_803CC1B8->func = fn_80037964;
        return;
    }
    memcpy(&task->pos, &pos, sizeof(Vec));
    memcpy(&task->rot, &q, sizeof(Quaternion));
}

// .text:0x80037964 size:0x20
void fn_80037964(void)
{
    fn_800B0A14_removeQueue();
}

// .text:0x80037768 size:0x1FC
void fn_80037768(RigidBody* body, s32 axis, s32 steps, f32 length, f32 center, f32 radius, f32 mass)
{
    f32 inertia;

    body->axis = axis;
    body->pivot.x = 0.0f;
    body->pivot.y = 0.0f;
    body->pivot.z = 0.0f;
    (&body->pivot.x)[axis] = -length * center;
    body->tip.x = 0.0f;
    body->tip.y = 0.0f;
    body->tip.z = 0.0f;
    (&body->tip.x)[axis] = length + (&body->pivot.x)[axis];
    PSVECSubtract(&body->tip, &body->pivot, &body->arm);
    body->mass = mass;
    body->invMass = 1.0f / mass;
    inertia = mass * ((radius * radius / 4.0f) + ((length * length) / 12.0f));
    body->radius = radius;
    body->inertia.z = inertia;
    body->inertia.y = inertia;
    body->inertia.x = inertia;
    (&body->inertia.x)[axis] = radius * (mass * radius) / 2.0f;
    body->invInertia.x = 1.0f / body->inertia.x;
    body->invInertia.y = 1.0f / body->inertia.y;
    body->invInertia.z = 1.0f / body->inertia.z;
    body->steps = steps;
    body->dt = (1.0f / 60.0f) / body->steps;
    body->_50 = 0.0f;
    body->_54 = 0.5f;
    PSMTXIdentity(body->rot);
    PSMTXIdentity(body->invRot);
    PSMTXIdentity(body->world);
    body->pos.z = 0.0f;
    body->pos.y = 0.0f;
    body->pos.x = 0.0f;
    body->quat.z = 0.0f;
    body->quat.y = 0.0f;
    body->quat.x = 0.0f;
    body->quat.w = 1.0f;
    body->force.z = 0.0f;
    body->force.y = 0.0f;
    body->force.x = 0.0f;
    body->vel.z = 0.0f;
    body->vel.y = 0.0f;
    body->vel.x = 0.0f;
    body->localVel.z = 0.0f;
    body->localVel.y = 0.0f;
    body->localVel.x = 0.0f;
    body->torque.z = 0.0f;
    body->torque.y = 0.0f;
    body->torque.x = 0.0f;
    body->angVel.z = 0.0f;
    body->angVel.y = 0.0f;
    body->angVel.x = 0.0f;
    body->_14D = 0;
    body->_14C = 0;
}

// .text:0x8003731C size:0x44C
void fn_8003731C(void)
{
}

// .text:0x80037054 size:0x2C8
void fn_80037054(void)
{
}
