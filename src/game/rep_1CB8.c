#include "game/rep_1CB8.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_D0.h"

extern f32 lbl_3_data_4444[10];

// .text:0x000B7E44 size:0xAC mapped:0x806F6ED8
// The target loads 0.06 through `addi; lfd 0(rX)` before the int-to-float
// conversion; this version loads it directly and schedules it later.
int fn_3_B7E44(s16 angle, f32 dist) {
    int diff;
    f32 offset;

    if (angle < 0x1E0 || angle > 0x620) {
        return 0;
    }
    diff = angle - 0x400;
    offset = 0.06 * (s16)(0x200 - ABS(diff));
    if (63.0f + offset < dist) {
        return 2;
    }
    return 55.0f + offset < dist;
}

// .text:0x000B7E10 size:0x34 mapped:0x806F6EA4
BOOL fn_3_B7E10(f32 x, f32 z) {
    if (z < x - 0.15f) {
        return TRUE;
    }
    return z < -x - 0.15f;
}

// .text:0x000B7DD8 size:0x38 mapped:0x806F6E6C
BOOL fn_3_B7DD8(f32 x, f32 z) {
    if (z > x + lbl_3_data_4444[5]) {
        return TRUE;
    }
    return z > -x + lbl_3_data_4444[5];
}

// .text:0x000B7D6C size:0x6C mapped:0x806F6E00
BOOL fn_3_B7D6C(f32 x, f32 z) {
    if (x > 0.0f) {
        if (z > x - 3.0f && z < 3.0f + x) {
            return TRUE;
        }
    } else {
        if (z > -x - 3.0f && z < 3.0f - x) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x000B7CDC size:0x90 mapped:0x806F6D70
BOOL fn_3_B7CDC(f32 x, f32 z) {
    VecSrcDst line;
    CollisionStruct hit;
    u8 type;

    line.src.x = x;
    line.src.y = -100.0f;
    line.src.z = z;
    line.dst.x = x;
    line.dst.y = 100.0f;
    line.dst.z = z;
    type = checkCollision(&line, &hit, 0, FALSE) & 0x7F;
    if (!(type != BALL_COLLISION_TYPE_GRASS && type != BALL_COLLISION_TYPE_DIRT &&
          type != BALL_COLLISION_TYPE_ROUGH_TERRAIN && type != BALL_COLLISION_TYPE_WATER && type != 0x32)) {
        return FALSE;
    }
    return TRUE;
}

// .text:0x000B7C2C size:0xB0 mapped:0x806F6CC0
BOOL fn_3_B7C2C(Vec* from, Vec* to) {
    VecSrcDst line;
    CollisionStruct hit;
    u8 type;

    line.src.x = from->x;
    line.src.y = -from->y;
    line.src.z = from->z;
    line.dst.x = to->x;
    line.dst.y = -to->y;
    line.dst.z = to->z;
    type = checkCollision(&line, &hit, 0, FALSE) & 0x7F;
    if (!(type != BALL_COLLISION_TYPE_WALL && type != BALL_COLLISION_TYPE_STRUCTURE &&
          type != BALL_COLLISION_TYPE_FOUL_LINE && type != BALL_COLLISION_TYPE_UNCLIMBABLE_WALL &&
          type != BALL_COLLISION_TYPE_PIT_WALL && type != BALL_COLLISION_TYPE_PIT &&
          type != BALL_COLLISION_TYPE_CHOMP_HAZARD)) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000B79AC size:0x280 mapped:0x806F6A40
f32 fn_3_B79AC(f32 x, f32 z) {
    VecSrcDst line;
    CollisionStruct hit;
    f32 dist;
    f32 scale;

    dist = dolsqrtf2(x * x + z * z);
    if (dist == 0.0f) {
        return 100.0f;
    }
    scale = 200.0f / dist;
    line.src.x = 0.0f;
    line.src.y = -0.5f;
    line.src.z = 0.0f;
    line.dst.x = x * scale;
    line.dst.y = -0.5f;
    line.dst.z = z * scale;
    checkCollision(&line, &hit, 0, FALSE);
    return dolsqrtf2(hit.position.x * hit.position.x + hit.position.z * hit.position.z) - dist;
}
