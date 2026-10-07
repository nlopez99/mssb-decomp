#ifndef __GAME_rep_D0_H_
#define __GAME_rep_D0_H_

#include "mssbTypes.h"
#include "Dolphin/vec.h"
#include "Dolphin/mtx.h"
#include "Dolphin/GX/GXTypes.h"

typedef struct _VecSrcDst {
    Vec src, dst;
} VecSrcDst;

typedef struct _CollisionStruct {
    Vec position, normal;
} CollisionStruct;

typedef struct _AABB_Box {
    Vec a, b;
} AABB_Box;


typedef struct _TriangleCollisionStruct {
    /*0x00*/ Mtx mtx1;
    /*0x30*/ Mtx mtx2;
    /*0x60*/ Vec normal;
    /*0x6C*/ f32 distance; // unsure
    /*0x70*/ f32 collisionDistance; // unsure
    /*0x74*/ E(u16, BALL_COLLISION_TYPE) collisionType;
} TriangleCollisionStruct; // size: 0x78

typedef struct _CollisionTriangle{
    /*0x00*/ Vec trianglePoint;
    /*0x0C*/ E(u16, BALL_COLLISION_TYPE) collisionType;
    // pad 2 bytes
} CollisionTriangle; // size:0x10

typedef struct _TriangleGroup {
    /*0x00*/ u8 _0;
    /*0x01*/ bool isTriangleList;
    /*0x02*/ u16 count;
    /*0x04*/ CollisionTriangle tris[];
} TriangleGroup; // size: at least 4, expandable

typedef struct _CollisionBox {
    /*0x00*/ AABB_Box* boundingBox;
    /*0x04*/ TriangleGroup* triangleGroups[]; // one per bounding box
} CollisionBox;

typedef struct _StadiumDrawTask {
    /*0x00*/ s32 type;
    /*0x04*/ void (*draw)(struct _StadiumDrawTask* task);
    /*0x08*/ Mtx _08;
    /*0x38*/ Mtx _38;
    /*0x68*/ void* layout;
    /*0x6C*/ s32 _6C;
} StadiumDrawTask; // size: 0x70

typedef struct _StadiumFog {
    /*0x00*/ GXColor color;
    /*0x04*/ f32 start;
    /*0x08*/ f32 end;
} StadiumFog; // size: 0xC

typedef struct _StadiumLight {
    /*0x00*/ f32 _00;
    /*0x04*/ f32 _04;
    /*0x08*/ f32 _08;
    /*0x0C*/ u8 _0C;
    /*0x0D*/ u8 _0D;
    /*0x0E*/ u16 _0E;
} StadiumLight; // size: 0x10

typedef struct _StadiumEnv {
    /*0x00*/ StadiumFog fog[3];
    /*0x24*/ StadiumLight lights[3];
    /*0x54*/ f32 rotSpeed;
    /*0x58*/ GXColor clearColor;
    /*0x5C*/ u8 _5C;
    /*0x5D*/ u8 _5D;
    /*0x5E*/ u8 _5E[2];
} StadiumEnv; // size: 0x60

typedef struct _UNK_StadiumCollision {
    /*0x000*/ void* _00;
    /*0x004*/ void* _04;
    /*0x008*/ StadiumDrawTask _008[2];
    /*0x0E8*/ StadiumDrawTask _0E8[2];
    /*0x1C8*/ StadiumDrawTask _1C8[2];
    /*0x2A8*/ StadiumDrawTask _2A8[2];
    /*0x388*/ StadiumDrawTask _388[2][2];
    /*0x548*/ StadiumDrawTask _548[2][2];
    /*0x708*/ u8 _708[2];
    /*0x70A*/ s16 numCollisionBoxes;
    /*0x70C*/ CollisionBox* pCollisionBoxes;
    /*0x710*/ f32 rotation;
    /*0x714*/ StadiumEnv env;
    /*0x774*/ u8 _774;
    /*0x778*/ CollisionBox* _778;
    /*0x77C*/ s16 _77C;
} UNK_StadiumCollision; // size: 0x780

extern UNK_StadiumCollision g_UNK_StadiumDetails; 

typedef enum _BALL_COLLISION_TYPE {
    BALL_COLLISION_TYPE_NONE,
    BALL_COLLISION_TYPE_GRASS,
    BALL_COLLISION_TYPE_WALL,
    BALL_COLLISION_TYPE_STRUCTURE,
    BALL_COLLISION_TYPE_FOUL_LINE,
    BALL_COLLISION_TYPE_UNCLIMBABLE_WALL,
    BALL_COLLISION_TYPE_DIRT,
    BALL_COLLISION_TYPE_PIT_WALL,
    BALL_COLLISION_TYPE_PIT,
    BALL_COLLISION_TYPE_ROUGH_TERRAIN,
    BALL_COLLISION_TYPE_WATER,
    BALL_COLLISION_TYPE_CHOMP_HAZARD,
    BALL_COLLISION_TYPE_FOUL = 0x80,
} BALL_COLLISION_TYPE;

BALL_COLLISION_TYPE fn_3_8D4(VecSrcDst* inVec, CollisionStruct* outCollision);
BALL_COLLISION_TYPE checkCollision(VecSrcDst* inVec, CollisionStruct* outCollision, int collisionCheckType, BOOL useBallCoords);
BALL_COLLISION_TYPE checkStatiumHazardCollisions(VecSrcDst* inVec, CollisionStruct* outCollision, s32* hitObject);
BALL_COLLISION_TYPE didCollideWithBoundingBoxes(VecSrcDst* inVec, CollisionStruct* outCollision, CollisionBox* boxes,
                                                s16 boxCount);
BOOL checkTriangleCollisions(TriangleCollisionStruct* collisionData, TriangleGroup* TriangleGroup);

#endif // !__GAME_rep_D0_H_
