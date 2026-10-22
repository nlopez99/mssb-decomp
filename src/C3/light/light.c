#include "C3/charPipeline.h"

extern void* _OSAllocFromHeap(u32 align, u32 size);

// .text:0x800BD300 size:0xA0
void LITXForm(Light *light, Mtx view) {
    Mtx m;

    CTRLBuildMatrix(&light->control, m);
    if (light->parent != NULL) {
        PSMTXConcat(light->parent, m, m);
    }
    PSMTXConcat(view, m, m);
    PSMTXMultVec(m, &light->position, &light->worldPosition);
    PSMTXInverse(m, m);
    PSMTXTranspose(m, m);
    PSMTXMultVec(m, &light->direction, &light->worldDirection);
}

// .text:0x800BD3A0 size:0xC
void LITInitColor(Light *light, GXColor color) {
    light->color = color;
}

// .text:0x800BD3AC size:0x10
void LITInitDir(Light *light, f32 nx, f32 ny, f32 nz) {
    light->direction.x = nx;
    light->direction.y = ny;
    light->direction.z = nz;
}

// .text:0x800BD3BC size:0x10
void LITInitPos(Light *light, f32 x, f32 y, f32 z) {
    light->position.x = x;
    light->position.y = y;
    light->position.z = z;
}

// .text:0x800BD3CC size:0x20
void LITInitAttn(Light *light, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2) {
    GXInitLightAttn(&light->lt_obj, a0, a1, a2, k0, k1, k2);
}

// .text:0x800BD3EC size:0x8C
void LITAlloc(Light **light) {
    *light = _OSAllocFromHeap(0x20, sizeof(Light));
    (*light)->position.z = 0.0f;
    (*light)->position.y = 0.0f;
    (*light)->position.x = 0.0f;
    (*light)->direction.y = 0.0f;
    (*light)->direction.x = 0.0f;
    (*light)->direction.z = 1.0f;
    (*light)->parent = NULL;
    (*light)->animPipe = NULL;
    (*light)->control.type = 0;
}
