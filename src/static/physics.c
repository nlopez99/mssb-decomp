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
    /* 0x104 */ Vec worldForce;
    /* 0x110 */ Vec force;
    /* 0x11C */ Vec vel;
    /* 0x128 */ Vec localVel;
    /* 0x134 */ Vec torque;
    /* 0x140 */ Vec angVel;
    /* 0x14C */ u8 _14C;
    /* 0x14D */ u8 _14D;
    /* 0x14E */ u8 axis;
    /* 0x150 */ f32 timeLeft;
} RigidBody; // size: 0x154

typedef struct PhysEnv {
    /* 0x00 */ s32 stiffness;
    /* 0x04 */ s32 damping;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 maxForce;
    /* 0x10 */ s32 minForce;
    /* 0x14 */ s32 restTorque;
    /* 0x18 */ s32 maxDepth;
    /* 0x1C */ s32 maxSpin;
    /* 0x20 */ s32 friction;
} PhysEnv; // size: 0x24

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

typedef struct RopeNode {
    /* 0x00 */ f32 mass;
    /* 0x04 */ f32 invMass;
    /* 0x08 */ f32 ground;
    /* 0x0C */ Vec pos;
    /* 0x18 */ Vec prevPos;
    /* 0x24 */ Vec vel;
    /* 0x30 */ Vec force;
    /* 0x3C */ u32 fixed;
} RopeNode; // size: 0x40

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
    /* 0x30 */ Vec angVel;
    /* 0x3C */ Vec vel;
    /* 0x48 */ Vec offset;
    /* 0x54 */ Vec pts[2];
    /* 0x6C */ Vec inertia;
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
    { { 0.0f, -0.89597f, 0.0f }, { 0.0f, 0.89597f, 0.0f } },
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
// The target saves one more FPR (f24) and has a 0x10 larger frame, so the stack
// slots and float registers differ; first draft, not tuned.
void fn_80039310(PhysState* st, f32 floor, f32 restEnergy)
{
    Mtx m3;
    Mtx m2;
    Mtx m;
    Quaternion q1;
    Vec v;
    Vec sum;
    Vec w;
    Vec k;
    Vec impulse;
    Quaternion q;
    Vec dir;
    Vec b;
    Vec a;
    Vec* pt;
    f32 invX;
    f32 invY;
    f32 invZ;
    f32 dt;
    f32 half;
    f32 mag;
    f32 energy;
    s32 i;

    invX = 1.0f / st->inertia.x;
    invY = 1.0f / st->inertia.y;
    invZ = 1.0f / st->inertia.z;
    dt = (1.0f / 60.0f) * lbl_803CB81C;
    mag = PSVECMag(&st->angVel);
    if (mag >= 50.0f) {
        PSVECScale(&st->angVel, 50.0f / mag, &st->angVel);
    }
    half = 0.5f * dt;
    PSVECScale(&st->vel, half, &v);
    PSMTXTransApply(st->mtx, st->mtx, v.x, v.y, v.z);
    PSVECScale(&st->vel, 0.5f * -dt, &v);
    PSVECAdd(&st->vel, &v, &st->vel);
    st->vel.y = (20.0f * dt) + st->vel.y;
    PSVECScale(&st->vel, half, &v);
    PSMTXTransApply(st->mtx, st->mtx, v.x, v.y, v.z);
    memcpy(&w, &st->angVel, sizeof(Vec));
    memset(&sum, 0, sizeof(Vec));
    k.x = invX * (st->inertia.y - st->inertia.z);
    k.y = invY * (st->inertia.z - st->inertia.x);
    k.z = invZ * (st->inertia.x - st->inertia.y);
    PSVECScale(&k, dt, &k);
    i = 0;
    do {
        v.y = k.y * ((w.z * w.x) - (0.2f * w.y));
        v.x = k.x * ((w.y * w.z) - (0.2f * w.x));
        v.z = k.z * ((w.x * w.y) - (0.2f * w.z));
        if (i == 1 || i == 2) {
            PSVECScale(&v, 2.0f, &v);
        }
        PSVECAdd(&sum, &v, &sum);
        PSVECScale(&v, 0.5f, &w);
        i++;
    } while (i < 4);
    PSVECScale(&sum, 1.0f / 6.0f, &v);
    PSVECAdd(&st->angVel, &v, &st->angVel);
    mag = PSVECMag(&st->angVel);
    if (mag > 0.0001f) {
        half = 0.5f * (-mag * dt);
        sum.x = sin(half);
        sum.y = cos(half);
        PSVECScale(&st->angVel, (1.0f / mag) * sum.x, (Vec*)&q1);
        q1.w = sum.y;
    } else {
        q1.w = 1.0f;
        q1.z = 0.0f;
        q1.y = 0.0f;
        q1.x = 0.0f;
    }
    PSMTXQuat(m3, &q1);
    PSMTXConcat(st->mtx, m3, st->mtx);
    i = 0;
    pt = st->pts;
    do {
        PSMTXMultVec(st->mtx, pt, &v);
        if (v.y > floor) {
            PSMTXCopy(st->mtx, m2);
            m2[2][3] = 0.0f;
            m2[1][3] = 0.0f;
            m2[0][3] = 0.0f;
            PSVECCrossProduct(&st->angVel, pt, &v);
            PSMTXMultVec(m2, &v, &v);
            PSVECAdd(&st->vel, &v, &v);
            impulse.x = v.x;
            impulse.y = 1.3f * -v.y;
            impulse.z = v.z;
            sum.x = 0.0f;
            sum.y = -1.0f;
            sum.z = 0.0f;
            PSMTXMultVec(m2, pt, &w);
            PSMTXScale(m2, invX, invY, invZ);
            PSMTXConcat(st->mtx, m2, m2);
            PSMTXTranspose(st->mtx, m3);
            PSMTXConcat(m2, m3, m2);
            PSVECCrossProduct(&w, &sum, &v);
            PSMTXMultVec(m2, &v, &v);
            PSVECCrossProduct(&v, &w, &v);
            impulse.y = impulse.y / (0.2962963f + PSVECDotProduct(&v, &sum));
            impulse.x *= -0.1f;
            impulse.z *= -0.1f;
            st->vel.y = st->vel.y + (impulse.y / 3.375f);
            st->vel.x = st->vel.x + impulse.x;
            st->vel.z = st->vel.z + impulse.z;
            PSMTXTranspose(st->mtx, m3);
            m3[2][3] = 0.0f;
            m3[1][3] = 0.0f;
            m3[0][3] = 0.0f;
            PSMTXMultVec(m3, &impulse, &v);
            PSVECCrossProduct(pt, &v, &v);
            sum.x = st->angVel.x * st->inertia.x;
            sum.y = st->angVel.y * st->inertia.y;
            sum.z = st->angVel.z * st->inertia.z;
            PSVECAdd(&sum, &v, &v);
            st->angVel.x = v.x * invX;
            st->angVel.y = v.y * invY;
            st->angVel.z = v.z * invZ;
            st->mtx[1][3] -= v.y - floor;
            lbl_803CBCA1 = 1;
        }
        i++;
        pt++;
    } while (i < 2);
    energy = (0.5f * ((st->vel.z * st->vel.z) + ((st->vel.x * st->vel.x) + (st->vel.y * st->vel.y))))
           + (0.5f * ((st->angVel.z * (st->inertia.z * st->angVel.z)) + ((st->angVel.x * (st->inertia.x * st->angVel.x)) + (st->angVel.y * (st->inertia.y * st->angVel.y)))));
    if (st->mtx[1][3] > 0.0f) {
        energy = (st->mtx[1][3] * 20.0f) + energy;
    } else {
        energy = -((st->mtx[1][3] * 20.0f) - energy);
    }
    if (energy <= restEnergy) {
        st->mtx[1][3] = floor;
        st->vel.z = 0.0f;
        st->vel.y = 0.0f;
        st->vel.x = 0.0f;
        st->angVel.z = 0.0f;
        st->angVel.y = 0.0f;
        st->angVel.x = 0.0f;
        PSMTXMultVec(st->mtx, &st->pts[0], &a);
        PSMTXMultVec(st->mtx, &st->pts[1], &b);
        PSVECSubtract(&a, &b, &a);
        half = 0.5f * (f32)sin(a.y / PSVECMag(&a));
        mag = sin(half);
        energy = cos(half);
        dir.x = 0.0f;
        dir.y = -1.0f;
        dir.z = 0.0f;
        PSVECCrossProduct(&dir, &a, &a);
        PSVECScale(&a, mag / PSVECMag(&a), (Vec*)&q);
        q.w = energy;
        PSMTXQuat(m, &q);
        PSMTXConcat(m, st->mtx, m);
        PSMTXCopy(m, st->mtx);
    }
}

// .text:0x80038F08 size:0x408
// The target reaches lbl_800F79B8 from lbl_800F79A0's base and has a 0x10 larger
// frame and one more saved GPR; this build loads lbl_800F79B8 directly.
void fn_80038F08(PhysActor* actor, PhysModel* model, u8 index)
{
    Mtx rate;
    Mtx m;
    Vec p;
    Vec prev;
    PhysState* st = &lbl_800F79B8;
    PhysBone* bone;
    PhysBone* child;
    f32 dt = (1.0f / 60.0f) * lbl_803CB81C;
    s32 r;

    bone = model->bones[actor->bones[st->_7C + index]];
    if (st->state < 0) {
        return;
    }
    if (st->state == 0) {
        PSMTXCopy(bone->mtx, st->mtx);
        PSMTXMultVec(bone->mtx, &st->offset, &p);
        st->mtx[0][3] = p.x;
        st->mtx[1][3] = p.y;
        st->mtx[2][3] = p.z;
        child = model->bones[actor->bones[st->_80]];
        PSMTXCopy(st->mtx, child->mtx);
        PSVECScale(&st->offset, -1.0f, &p);
        PSMTXMultVec(st->mtx, &p, &p);
        child->mtx[0][3] = p.x;
        child->mtx[1][3] = p.y;
        child->mtx[2][3] = p.z;
        st->state++;
    } else if (st->state == 1) {
        PSMTXMultVec(bone->mtx, &st->offset, &p);
        prev.x = st->mtx[0][3];
        prev.y = st->mtx[1][3];
        prev.z = st->mtx[2][3];
        PSVECSubtract(&p, &prev, &st->vel);
        if (lbl_803CBCA0) {
            memcpy(&st->vel, &lbl_800F79A0[1], sizeof(Vec));
        } else {
            PSVECAdd(&st->vel, &lbl_800F79A0[0], &st->vel);
        }
        PSVECScale(&st->vel, lbl_803CB824, &st->vel);
        PSVECScale(&st->vel, 1.0f / dt, &st->vel);
        for (r = 0; r < 3; r++) {
            rate[r][0] = (bone->mtx[r][0] - st->mtx[r][0]) / dt;
            rate[r][1] = (bone->mtx[r][1] - st->mtx[r][1]) / dt;
            rate[r][2] = (bone->mtx[r][2] - st->mtx[r][2]) / dt;
        }
        rate[2][3] = 0.0f;
        rate[1][3] = 0.0f;
        rate[0][3] = 0.0f;
        PSMTXTranspose(bone->mtx, m);
        PSMTXConcat(rate, m, rate);
        st->angVel.x = rate[2][1];
        st->angVel.y = rate[0][2];
        st->angVel.z = rate[1][0];
        PSMTXMultVec(m, &st->angVel, &st->angVel);
        PSMTXCopy(bone->mtx, st->mtx);
        st->mtx[0][3] = p.x;
        st->mtx[1][3] = p.y;
        st->mtx[2][3] = p.z;
        PSVECScale(&st->angVel, 0.5f * lbl_803CB824, &st->angVel);
        child = model->bones[actor->bones[st->_80]];
        PSMTXCopy(st->mtx, child->mtx);
        PSVECScale(&st->offset, -1.0f, &p);
        PSMTXMultVec(st->mtx, &p, &p);
        child->mtx[0][3] = p.x;
        child->mtx[1][3] = p.y;
        child->mtx[2][3] = p.z;
        st->state++;
    } else {
        PSMTXTrans(m, lbl_8036E548._C38.x, lbl_8036E548._C38.y, lbl_8036E548._C38.z);
        PSMTXInverse(m, m);
        fn_80039310(st, -0.12675f, 1.8f);
        child = model->bones[actor->bones[st->_80]];
        PSMTXCopy(st->mtx, child->mtx);
        PSVECScale(&st->offset, -1.0f, &p);
        PSMTXMultVec(st->mtx, &p, &p);
        child->mtx[0][3] = p.x;
        child->mtx[1][3] = p.y;
        child->mtx[2][3] = p.z;
        st->state += st->state == 2;
    }
}

// .text:0x80038EC4 size:0x44
void fn_80038EC4(PhysActor* actor, PhysModel** ref, s32 index)
{
    if (lbl_800F79B8.state < 0) {
        lbl_800F79B8.state = 0;
    }
    fn_80038F08(actor, *ref, index);
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
RopeNode* fn_80038CD0(s32 count, RopeParams* params, RopeNode* nodes, f32 height, f32 mass)
{
    RopeNode* node;
    s32 i;

    memset(nodes, 0, count * sizeof(RopeNode));
    node = nodes;
    for (i = 0; i < count; i++) {
        if (i == 0) {
            node->mass = mass;
        } else if (i == count - 1) {
            node->mass = mass;
        } else {
            node->mass = 2.0f * mass;
        }
        node->ground = height;
        node->invMass = 1.0f / node->mass;
        node->pos.x = 0.0f;
        node->pos.y = (params->_00 * i) + height;
        node->pos.z = 0.0f;
        memcpy(&node->prevPos, &node->pos, sizeof(Vec));
        node->fixed = i == 0;
        node++;
    }
    return nodes;
}

// .text:0x80038B48 size:0x188
void fn_80038B48(RopeParams* params, RopeNode* nodes, s32 count, Vec* force)
{
    Vec accel;
    Vec scaled;
    Vec step;
    Vec next;
    RopeNode* node;
    s32 j;
    s32 i;
    f32 dt2;
    f32 inv2dt;
    f32 y;
    f32 depth;

    PSVECScale(force, params->dt, &scaled);
    for (i = 0; i < params->steps; i++) {
        fn_800387B0(params, nodes, count, &scaled);
        node = nodes;
        for (j = 0; j < count; j++) {
            PSVECScale(&node->force, node->invMass, &accel);
            inv2dt = params->_24;
            dt2 = params->dt2;
            PSVECScale(&node->pos, 2.0f, &next);
            PSVECSubtract(&next, &node->prevPos, &next);
            PSVECScale(&accel, dt2, &step);
            PSVECAdd(&next, &step, &next);
            PSVECSubtract(&next, &node->prevPos, &node->vel);
            PSVECScale(&node->vel, inv2dt, &node->vel);
            memcpy(&node->prevPos, &node->pos, sizeof(Vec));
            memcpy(&node->pos, &next, sizeof(Vec));
            if (node->fixed == 0) {
                y = node->pos.y;
                depth = y - node->ground;
                if (depth < 0.0f) {
                    node->pos.y = -((depth * params->_04) - y);
                    y = node->prevPos.y;
                    depth = y - node->ground;
                    node->prevPos.y = -((depth * params->_04) - y);
                }
            }
            node++;
        }
    }
}

// .text:0x800387B0 size:0x398
// Registers only: the spring loop swaps node and prev (r28/r29); declaration orders
// and loop forms tried.
void fn_800387B0(RopeParams* params, RopeNode* nodes, s32 count, Vec* force)
{
    Vec rel;
    Vec dir;
    Vec drag;
    RopeNode* node;
    RopeNode* prev;
    RopeNode* cur;
    s32 i;
    s32 j;
    f32 len;
    f32 friction;
    f32 spring;
    f32 damp;
    f32 horiz;
    f32 speed;

    node = nodes;
    for (i = 0; i < count; i++) {
        memset(&node->force, 0, sizeof(Vec));
        if (node->fixed == 0) {
            node->force.y = -9.80665f * node->mass;
        }
        if (i == count - 1) {
            PSVECAdd(&node->force, force, &node->force);
        }
        node++;
    }

    j = count;
    node = &nodes[count];
    while (node--, --j != 0) {
        prev = &nodes[j - 1];
        PSVECSubtract(&node->pos, &prev->pos, &dir);
        PSVECSubtract(&node->vel, &prev->vel, &rel);
        len = PSVECMag(&dir);
        if (len != 0.0f) {
            spring = params->_08 * (len - params->_00);
            damp = params->_0C * (PSVECDotProduct(&rel, &dir) / len);
            PSVECNormalize(&dir, &dir);
            PSVECScale(&dir, -(spring + damp), &dir);
            if (node->fixed == 0) {
                PSVECAdd(&node->force, &dir, &node->force);
            }
            PSVECScale(&dir, -1.0f, &dir);
            if (prev->fixed == 0) {
                PSVECAdd(&prev->force, &dir, &prev->force);
            }
        }
    }

    cur = nodes;
    for (i = 0; i < count; i++) {
        if (cur->fixed == 0) {
            memcpy(&rel, &cur->vel, sizeof(Vec));
            memcpy(&dir, &cur->force, sizeof(Vec));
            PSVECScale(&dir, cur->invMass, &dir);
            PSVECScale(&dir, params->dt, &dir);
            PSVECAdd(&rel, &dir, &rel);
            memset(&drag, 0, sizeof(Vec));
            speed = PSVECMag(&rel);
            if (speed) {
                PSVECScale(&rel, -1.0f, &dir);
                PSVECNormalize(&dir, &dir);
                PSVECScale(&dir, params->_14 * (speed * speed), &dir);
                PSVECAdd(&drag, &dir, &drag);
            }
            if (cur->pos.y <= cur->ground) {
                if (cur->force.y < 0.0f) {
                    friction = cur->force.y * params->_10;
                    if (friction < 0.0f) {
                        friction = -friction;
                    }
                    memcpy(&dir, &cur->force, sizeof(Vec));
                    dir.y = 0.0f;
                    horiz = PSVECMag(&dir);
                    rel.y = 0.0f;
                    speed = PSVECMag(&rel);
                    if (speed || horiz > friction) {
                        if (speed) {
                            PSVECNormalize(&rel, &dir);
                        } else {
                            PSVECNormalize(&dir, &dir);
                        }
                        PSVECScale(&dir, -friction, &dir);
                        PSVECAdd(&drag, &dir, &drag);
                    } else {
                        PSVECScale(&cur->force, -1.0f, &dir);
                        PSVECAdd(&drag, &dir, &drag);
                    }
                }
            }
            PSVECAdd(&cur->force, &drag, &cur->force);
        }
        cur++;
    }
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
void fn_8003819C(RigidBody* body)
{
    Vec point;
    Vec f;
    Vec vel;
    Vec g;
    Vec torque;
    s32 i;

    f.x = 0.0f;
    f.y = 9.80665f * body->mass;
    f.z = 0.0f;
    PSMTXMultVec(body->invRot, &f, &f);
    PSVECAdd(&body->force, &f, &body->force);
    for (i = 0; i <= 10; i++) {
        PSVECScale(&body->arm, i / 10.0f, &point);
        PSVECAdd(&body->pivot, &point, &point);
        PSVECCrossProduct(&body->angVel, &point, &vel);
        PSVECAdd(&vel, &body->localVel, &vel);
        PSVECScale(&vel, body->_50, &f);
        if (body->_14D && body->_14C) {
            g.x = 0.0f;
            g.y = (-9.80665f * body->mass) / 20.0f;
            g.z = 0.0f;
            if (i > 0 && i < 10) {
                g.y *= 2.0f;
            }
            PSMTXMultVec(body->invRot, &g, &g);
            PSVECAdd(&f, &g, &f);
        } else if ((body->_14D && i == 0) || (body->_14C && i == 10)) {
            g.x = 0.0f;
            g.y = -9.80665f * body->mass;
            g.z = 0.0f;
            PSMTXMultVec(body->invRot, &g, &g);
            PSVECAdd(&f, &g, &f);
        }
        PSVECAdd(&body->force, &f, &body->force);
        PSVECCrossProduct(&point, &f, &torque);
        PSVECAdd(&body->torque, &torque, &body->torque);
    }
}

// .text:0x80037BAC size:0x5F0
// The target keeps &tipW in r31 (six saved GPRs, frame 0x230); this build keeps
// five and re-forms &tipW each time, so every later register differs.
s32 fn_80037BAC(RigidBody* body)
{
    RigidBody b;
    Vec tipW;
    Vec pivotW;
    Vec v;
    Vec up;
    Vec lv;
    Vec av;
    Vec t;
    Quaternion q;
    Vec* pts[2];
    s32 contact[2];
    RigidBody* p = &b;
    f32 remaining;
    f32 denom;
    s32 i;

    remaining = body->dt;
    memcpy(p, body, sizeof(RigidBody) - sizeof(f32));
    pts[0] = &p->pivot;
    pts[1] = &p->tip;
    PSMTXMultVec(p->world, &p->pivot, &pivotW);
    PSMTXMultVec(p->world, &p->tip, &tipW);
    p->timeLeft = p->dt;
    do {
        PSMTXMultVec(p->invRot, &p->vel, &p->localVel);
        fn_8003819C(p);
        PSVECScale(&p->force, p->invMass * p->timeLeft, &v);
        PSMTXMultVec(p->rot, &v, &v);
        PSVECAdd(&p->vel, &v, &p->vel);
        PSVECScale(&p->vel, p->timeLeft, &v);
        PSVECAdd(&p->pos, &v, &p->pos);
        v.x = p->inertia.x * p->angVel.x;
        v.y = p->inertia.y * p->angVel.y;
        v.z = p->inertia.z * p->angVel.z;
        PSVECCrossProduct(&p->angVel, &v, &v);
        PSVECSubtract(&p->torque, &v, &v);
        PSVECScale(&v, p->timeLeft, &v);
        p->angVel.x += v.x * p->invInertia.x;
        p->angVel.y += v.y * p->invInertia.y;
        p->angVel.z += v.z * p->invInertia.z;
        PSVECScale(&p->angVel, p->timeLeft, (Vec*)&q);
        q.w = 0.0f;
        PSQUATMultiply(&p->quat, &q, &q);
        PSQUATScale(&q, 0.5f * p->timeLeft, &q);
        PSQUATAdd(&p->quat, &q, &q);
        if (q.x || q.y || q.z || q.w) {
            PSQUATNormalize(&q, &p->quat);
        } else {
            memcpy(&p->quat, &q, sizeof(Quaternion));
        }
        p->torque.z = 0.0f;
        p->torque.y = 0.0f;
        p->torque.x = 0.0f;
        p->force.z = 0.0f;
        p->force.y = 0.0f;
        p->force.x = 0.0f;
        PSMTXQuat(p->rot, &p->quat);
        PSMTXInverse(p->rot, p->invRot);
        PSMTXTransApply(p->rot, p->world, p->pos.x, p->pos.y, p->pos.z);
        PSMTXMultVec(p->world, &p->pivot, &pivotW);
        PSMTXMultVec(p->world, &p->tip, &tipW);
        contact[0] = pivotW.y < -p->radius ? 0 : pivotW.y > p->radius ? -1 : 1;
        contact[1] = tipW.y < -p->radius ? 0 : tipW.y > p->radius ? -1 : 1;
        if (contact[0] == 0) {
            p->_14D = 0;
        } else if (p->_14D) {
            contact[0] = 0;
        }
        if (contact[1] == 0) {
            p->_14C = 0;
        } else if (p->_14C) {
            contact[1] = 0;
        }
        if (contact[0] != -1 && contact[1] != -1) {
            PSMTXMultVec(p->invRot, &p->vel, &p->localVel);
            memcpy(&lv, &p->localVel, sizeof(Vec));
            memcpy(&av, &p->angVel, sizeof(Vec));
            up.x = 0.0f;
            up.y = 1.0f;
            up.z = 0.0f;
            PSMTXMultVec(p->invRot, &up, &up);
            i = 1;
            do {
                if (contact[i] != 0) {
                    PSVECCrossProduct(&av, pts[i], &v);
                    PSVECAdd(&lv, &v, &v);
                    PSMTXMultVec(p->rot, &v, &t);
                    if (t.y > 0.0f) {
                        PSVECCrossProduct(pts[i], &up, &t);
                        t.x *= p->invInertia.x;
                        t.y *= p->invInertia.y;
                        t.z *= p->invInertia.z;
                        PSVECCrossProduct(&t, pts[i], &t);
                        denom = p->invMass + PSVECDotProduct(&up, &t);
                        PSVECScale(&up, ((1.0f + p->_54) * -PSVECDotProduct(&v, &up)) / denom, &v);
                        PSVECScale(&v, p->invMass, &t);
                        PSVECAdd(&p->localVel, &t, &p->localVel);
                        PSVECCrossProduct(pts[i], &v, &v);
                        v.x *= p->invInertia.x;
                        v.y *= p->invInertia.y;
                        v.z *= p->invInertia.z;
                        PSVECAdd(&p->angVel, &v, &p->angVel);
                    }
                    if (i != 0) {
                        p->_14C = 1;
                    } else {
                        p->_14D = 1;
                    }
                }
            } while (i-- != 0);
            PSMTXMultVec(p->rot, &p->localVel, &p->vel);
            remaining -= p->timeLeft;
            if (p->timeLeft < remaining) {
                p->timeLeft = remaining;
            }
            memcpy(body, p, sizeof(RigidBody) - sizeof(f32));
        } else {
            memcpy(p, body, sizeof(RigidBody) - sizeof(f32));
            p->timeLeft *= 0.5f;
        }
    } while (remaining > 0.0f);
    return 0;
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
s32 fn_8003731C(RigidBody* body, PhysEnv* env)
{
    Vec world[2];
    Vec local[2];
    Vec vel;
    Vec f;
    Vec fr;
    Vec saved;
    Vec torque;
    Vec down;
    f32 stiffness = env->stiffness / 100000.0f;
    f32 damping = env->damping / 100000.0f;
    f32 maxForce = env->maxForce / 100000.0f;
    f32 minForce = env->minForce / 100000.0f;
    f32 restTorque = env->restTorque / 100000.0f;
    f32 maxDepth = env->maxDepth / 100000.0f;
    f32 friction = env->friction / 100000.0f;
    f32 mag;
    s32 i;

    memcpy(&saved, &body->worldForce, sizeof(Vec));
    memset(&body->worldForce, 0, sizeof(Vec));
    memset(&body->force, 0, sizeof(Vec));
    memset(&body->torque, 0, sizeof(Vec));
    down.x = down.z = 0.0f;
    down.y = -body->radius;
    PSMTXMultVec(body->invRot, &down, &down);
    PSVECScale(&body->vel, -body->_50, &f);
    PSVECAdd(&body->worldForce, &f, &body->worldForce);
    PSVECScale(&body->angVel, -body->_50, &torque);
    (&torque.x)[body->axis] = 0.0f;
    PSVECAdd(&body->torque, &torque, &body->torque);
    for (i = 2; i-- != 0;) {
        PSVECAdd(i == 1 ? &body->pivot : &body->tip, &down, &local[i]);
        PSMTXMultVec(body->world, &local[i], &world[i]);
        memset(&f, 0, sizeof(Vec));
        f.y = -world[i].y;
        if (f.y >= 0.0f) {
            if (maxDepth && f.y > maxDepth) {
                f.y = maxDepth;
            }
            PSVECCrossProduct(&local[i], &body->angVel, &vel);
            PSMTXMultVec(body->rot, &vel, &vel);
            PSVECAdd(&body->vel, &vel, &vel);
            f.y = (stiffness * f.y) + (damping * -vel.y);
            mag = fabs(f.y);
            if (maxForce && mag > maxForce) {
                f.y = maxForce * (f.y / mag);
            } else if (mag < minForce) {
                continue;
            }
            if (friction) {
                fr.y = 0.0f;
                fr.x = -vel.x;
                fr.z = -vel.z;
                PSVECScale(&fr, friction, &fr);
                f.x += fr.x;
                f.z += fr.z;
            }
            PSVECAdd(&body->worldForce, &f, &body->worldForce);
            PSMTXMultVec(body->invRot, &f, &f);
            PSVECCrossProduct(&local[i], &f, &torque);
            PSVECAdd(&body->torque, &torque, &body->torque);
        }
    }
    f.x = 0.0f;
    f.y = -9.80665f * body->mass;
    f.z = 0.0f;
    PSVECAdd(&body->worldForce, &f, &body->worldForce);
    if (PSVECMag(&body->torque) < restTorque) {
        memset(&body->torque, 0, sizeof(Vec));
    }
    return 0;
}

// .text:0x80037054 size:0x2C8
s32 fn_80037054(RigidBody* body, PhysEnv* env)
{
    RigidBody b;
    Vec dv;
    Vec dp;
    Vec w;
    Quaternion q;
    f32 maxSpin;
    f32 t = 1.0f / 60.0f;
    f32 mag;

    body->timeLeft = body->dt;
    memcpy(&b, body, sizeof(RigidBody));
    do {
        fn_8003731C(&b, env);
        PSVECScale(&b.worldForce, b.invMass * b.timeLeft, &dp);
        PSVECAdd(&b.vel, &dp, &b.vel);
        PSVECScale(&b.vel, b.timeLeft, &dv);
        PSVECAdd(&b.pos, &dv, &b.pos);
        maxSpin = env->maxSpin / 100000.0f;
        w.x = b.inertia.x * b.angVel.x;
        w.y = b.inertia.y * b.angVel.y;
        w.z = b.inertia.z * b.angVel.z;
        PSVECCrossProduct(&b.angVel, &w, &w);
        PSVECSubtract(&b.torque, &w, &w);
        w.x *= b.invInertia.x;
        w.y *= b.invInertia.y;
        w.z *= b.invInertia.z;
        PSVECScale(&w, b.timeLeft, &w);
        PSVECAdd(&b.angVel, &w, &b.angVel);
        if (maxSpin) {
            mag = PSVECMag(&b.angVel);
            if (mag > maxSpin) {
                PSVECScale(&b.angVel, maxSpin / mag, &b.angVel);
            }
        }
        memcpy(&q, &b.angVel, sizeof(Vec));
        q.w = 0.0f;
        PSQUATMultiply(&b.quat, &q, &q);
        PSQUATScale(&q, 0.5f * b.timeLeft, &q);
        PSQUATAdd(&b.quat, &q, &b.quat);
        PSMTXQuat(b.rot, &b.quat);
        PSMTXInverse(b.rot, b.invRot);
        PSMTXTransApply(b.rot, b.world, b.pos.x, b.pos.y, b.pos.z);
        PSMTXMultVec(b.invRot, &b.vel, &b.localVel);
        t -= b.timeLeft;
    } while (t > 0.0f);
    memcpy(body, &b, sizeof(RigidBody));
    return 0;
}
