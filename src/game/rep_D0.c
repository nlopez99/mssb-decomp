#include "game/UnknownHomes_Game.h"
#include "game/rep_D0.h"
#include "header_rep_data.h"
#include "Dolphin/stl.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1D58.h"

extern void makeLookAtMatrix(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target);

typedef struct StadiumObjectCollision {
    /* 0x00 */ u8 _00[8];
    /* 0x08 */ TriangleGroup* triangles;
} StadiumObjectCollision;

extern struct {
    /* 0x00 */ u8 _00[0x64];
    /* 0x64 */ s16 numAreas;
} lbl_3_common_bss_350E4;

Vec lbl_3_data_1F8 = { 0.0f, 1.0f, 0.0f };
Vec lbl_3_data_204 = { 0.0f, 0.0f, 0.0f };
Vec lbl_3_data_210 = { 0.0f, 1.0f, 0.0f };
Vec lbl_3_data_21C = { 0.0f, 0.0f, 0.0f };

#define SIGN_BITS(f) (*(u32*)&(f))

// .text:0x000010E0 size:0x3C4 mapped:0x80640174
BOOL checkTriangleCollisions(TriangleCollisionStruct* collisionData, TriangleGroup* _triangleGroup) {
#define O_GROUP ((TriangleGroup*)_triangleGroup)
#define O_TRI ((CollisionTriangle*)_triangleGroup)

    Vec tri[3];
    Vec dist[3];
    u32 remainingTriangles;
    u32 didVecPassTriangle;
    u32 isBackwardsTriangle;

    BOOL ret = FALSE;
    f32 d;
    while (true) {
        bool isList;
        remainingTriangles = O_GROUP->count;
        if (remainingTriangles == 0)
            break;

        isList = O_GROUP->isTriangleList;
        // this should be reassigned to r24? but they're different types?
        // i hope it's not a union
        O_TRI = O_GROUP->tris;
        if (!isList) {
            // grou of 3 verts to make up a triangle
            do {
                MTXMultVec(collisionData->mtx1, &O_TRI[0].trianglePoint, &tri[00]);
                MTXMultVec(collisionData->mtx1, &O_TRI[1].trianglePoint, &tri[01]);
                MTXMultVec(collisionData->mtx1, &O_TRI[2].trianglePoint, &tri[02]);
                didVecPassTriangle = tri[00].x * tri[01].y - tri[01].x * tri[00].y >= 0;
                didVecPassTriangle &= tri[01].x * tri[02].y - tri[02].x * tri[01].y >= 0;
                didVecPassTriangle &= tri[02].x * tri[00].y - tri[00].x * tri[02].y >= 0;
                if (didVecPassTriangle) {
                    VECSubtract(&tri[01], &tri[00], &dist[0]);
                    VECSubtract(&tri[02], &tri[01], &dist[1]);
                    VECCrossProduct(&dist[0], &dist[1], &dist[2]);
                    d = -VECDotProduct(&dist[2], &tri[00]) / dist[2].z;
                    if (d >= 0.f && collisionData->collisionDistance > d) {
                        collisionData->collisionDistance = d;
                        ret = TRUE;
                        collisionData->collisionType = O_TRI[2].collisionType;
                        collisionData->normal = dist[2];
                    }
                }
                O_TRI += 3;
            } while (--remainingTriangles);
        } else {
            // the first 3 verts describe a triangle, after that each new vert replaces the oldest vert to make a
            // triangle fan
            isBackwardsTriangle = false;
            MTXMultVec(collisionData->mtx1, &O_TRI[0].trianglePoint, &tri[00]);
            MTXMultVec(collisionData->mtx1, &O_TRI[1].trianglePoint, &tri[01]);
            O_TRI += 2;
            do {
                MTXMultVec(collisionData->mtx1, &O_TRI->trianglePoint, &tri[02]);
                dist[0].x = tri[00].x * tri[01].y - tri[01].x * tri[00].y;
                dist[0].y = tri[01].x * tri[02].y - tri[02].x * tri[01].y;
                dist[0].z = tri[02].x * tri[00].y - tri[00].x * tri[02].y;

                if (isBackwardsTriangle) {
                    didVecPassTriangle = dist[0].x <= 0.f & dist[0].y <= 0.f & dist[0].z <= 0.f;
                } else {
                    didVecPassTriangle = dist[0].x >= 0.f & dist[0].y >= 0.f & dist[0].z >= 0.f;
                }

                if (didVecPassTriangle) {
                    VECSubtract(&tri[01], &tri[00], &dist[0]);
                    VECSubtract(&tri[02], &tri[01], &dist[1]);
                    VECCrossProduct(&dist[0], &dist[1], &dist[2]);
                    d = -VECDotProduct(&dist[2], &tri[00]) / dist[2].z;
                    if (d >= 0.f && collisionData->collisionDistance > d) {
                        collisionData->collisionDistance = d;
                        collisionData->collisionType = O_TRI[0].collisionType;
                        if (!isBackwardsTriangle) {
                            collisionData->normal = dist[2];
                        } else {
                            collisionData->normal.x = -dist[2].x;
                            collisionData->normal.y = -dist[2].y;
                            collisionData->normal.z = -dist[2].z;
                        }
                        ret = TRUE;
                    }
                }
                tri[00] = tri[01];
                tri[01] = *&tri[02];
                isBackwardsTriangle ^= 1;
                O_TRI++;
            } while (--remainingTriangles);
        }
    }

    return ret;
}

// .text:0x00000DF0 size:0x2F0 mapped:0x8063FE84
BALL_COLLISION_TYPE didCollideWithBoundingBoxes(VecSrcDst* inVec, CollisionStruct* outCollision, CollisionBox* boxes,
                                                s16 boxCount) {
    u8 outside[256];
    TriangleCollisionStruct col;
    Vec d[4];
    Mtx inv;
    TriangleGroup** group;
    int count;
    int n;
    u32 allOutside;
    AABB_Box* box;
    u8* flag;

    count = boxCount;
    box = boxes->boundingBox;
    memset(outside, 1, count);
    n = count;
    flag = outside;
    allOutside = TRUE;
    do {
        PSVECSubtract(&inVec->src, &box->a, &d[0]);
        PSVECSubtract(&box->b, &inVec->src, &d[1]);
        PSVECSubtract(&inVec->dst, &box->a, &d[2]);
        PSVECSubtract(&box->b, &inVec->dst, &d[3]);
        if (!(((SIGN_BITS(d[0].x) & SIGN_BITS(d[2].x)) | (SIGN_BITS(d[1].x) & SIGN_BITS(d[3].x))) & 0x80000000) &&
            !(((SIGN_BITS(d[0].y) & SIGN_BITS(d[2].y)) | (SIGN_BITS(d[1].y) & SIGN_BITS(d[3].y))) & 0x80000000) &&
            !(((SIGN_BITS(d[0].z) & SIGN_BITS(d[2].z)) | (SIGN_BITS(d[1].z) & SIGN_BITS(d[3].z))) & 0x80000000)) {
            *flag = 0;
            allOutside = FALSE;
        }
        box++;
        flag++;
    } while (--n);

    if (allOutside) {
        return BALL_COLLISION_TYPE_NONE;
    }

    makeLookAtMatrix(col.mtx1, &inVec->src, &lbl_3_data_1F8, &inVec->dst);
    col.collisionDistance = col.distance = dolsqrtf2(PSVECSquareDistance(&inVec->dst, &inVec->src));
    col.collisionType = BALL_COLLISION_TYPE_NONE;

    flag = outside;
    group = boxes->triangleGroups;
    do {
        if (*flag++ == 0) {
            checkTriangleCollisions(&col, *group);
        }
        group++;
    } while (--count);

    if (col.collisionType != BALL_COLLISION_TYPE_NONE) {
        PSMTXInverse(col.mtx1, inv);
        lbl_3_data_204.z = -col.collisionDistance;
        PSMTXMultVec(inv, &lbl_3_data_204, &outCollision->position);
        PSMTXTranspose(col.mtx1, inv);
        PSMTXMultVec(inv, &col.normal, &outCollision->normal);
        PSVECNormalize(&outCollision->normal, &outCollision->normal);
        return col.collisionType;
    }
    return BALL_COLLISION_TYPE_NONE;
}

// .text:0x00000A6C size:0x384 mapped:0x8063FB00
BALL_COLLISION_TYPE checkStatiumHazardCollisions(VecSrcDst* inVec, CollisionStruct* outCollision, s32* hitObject) {
    u8 outside[256];
    TriangleCollisionStruct col;
    Vec d[4];
    Mtx inv;
    Mtx lookAt;
    Vec min;
    Vec max;
    s32* objects;
    StadiumObjectCollision* object;
    u32 area;
    u32 allOutside;
    u8* flag;
    u32 i;
    u32 n;

    memset(outside, 1, lbl_3_common_bss_350E4.numAreas);
    area = lbl_3_common_bss_350E4.numAreas;
    flag = outside;
    allOutside = TRUE;
    while (area--) {
        fn_3_B85DC(area, &min, &max);
        PSVECSubtract(&inVec->src, &min, &d[0]);
        PSVECSubtract(&max, &inVec->src, &d[1]);
        PSVECSubtract(&inVec->dst, &min, &d[2]);
        PSVECSubtract(&max, &inVec->dst, &d[3]);
        if (!(((SIGN_BITS(d[0].x) & SIGN_BITS(d[2].x)) | (SIGN_BITS(d[1].x) & SIGN_BITS(d[3].x))) & 0x80000000) &&
            !(((SIGN_BITS(d[0].y) & SIGN_BITS(d[2].y)) | (SIGN_BITS(d[1].y) & SIGN_BITS(d[3].y))) & 0x80000000) &&
            !(((SIGN_BITS(d[0].z) & SIGN_BITS(d[2].z)) | (SIGN_BITS(d[1].z) & SIGN_BITS(d[3].z))) & 0x80000000)) {
            *flag = 0;
            allOutside = FALSE;
        }
        flag++;
    }

    if (allOutside) {
        return BALL_COLLISION_TYPE_NONE;
    }

    makeLookAtMatrix(lookAt, &inVec->src, &lbl_3_data_210, &inVec->dst);
    col.collisionDistance = col.distance = dolsqrtf2(PSVECSquareDistance(&inVec->dst, &inVec->src));
    col.collisionType = BALL_COLLISION_TYPE_NONE;

    i = lbl_3_common_bss_350E4.numAreas;
    flag = outside;
    while (i--) {
        if (*flag++ != 0) {
            continue;
        }
        n = fn_3_B85A8(i, &objects);
        while (n--) {
            object = fn_3_B91C8(g_d_GameSettings.StadiumID, objects[n], col.mtx1);
            if (object != NULL) {
                PSMTXConcat(lookAt, col.mtx1, col.mtx1);
                if (checkTriangleCollisions(&col, object->triangles)) {
                    *hitObject = objects[n];
                }
            }
        }
    }

    if (col.collisionType != BALL_COLLISION_TYPE_NONE) {
        PSMTXCopy(lookAt, col.mtx1);
        PSMTXInverse(col.mtx1, inv);
        lbl_3_data_21C.z = -col.collisionDistance;
        PSMTXMultVec(inv, &lbl_3_data_21C, &outCollision->position);
        PSMTXTranspose(col.mtx1, inv);
        PSMTXMultVec(inv, &col.normal, &outCollision->normal);
        PSVECNormalize(&outCollision->normal, &outCollision->normal);
        return col.collisionType;
    }
    return BALL_COLLISION_TYPE_NONE;
}

// .text:0x00000914 size:0x158 mapped:0x8063F9A8
BALL_COLLISION_TYPE checkCollision(VecSrcDst* inVec, CollisionStruct* outCollision, int collisionCheckType,
                                   BOOL useBallCoords) {
    VecSrcDst p;
    s32 object;
    BALL_COLLISION_TYPE ret = 0;
    if (collisionCheckType) {
        if (useBallCoords && (g_d_GameSettings.StadiumID == STADIUM_ID_WARIO_PALACE ||
                              g_d_GameSettings.StadiumID == STADIUM_ID_YOHSI_PARK ||
                              g_d_GameSettings.StadiumID == STADIUM_ID_DK_JUNGLE)) {
            memcpy(&p.dst, &g_Ball.AtBat_Contact_BallPos, sizeof(p.dst));
            memcpy(&p.src, &g_Ball.pastCoordinates[4], sizeof(p.src));
            p.src.y *= -1.f;
            p.dst.y *= -1.f;
        } else {
            memcpy(&p, inVec, sizeof(p));
        }
        ret = checkStatiumHazardCollisions(&p, outCollision, &object);
        if (ret) {
            if (collisionCheckType == 2 && (ret & BALL_COLLISION_TYPE_FOUL)) {
                ret = BALL_COLLISION_TYPE_NONE;
            } else {
                processStadiumObjectFunction(g_d_GameSettings.StadiumID, object, ret, outCollision);
                goto end;
            }
        }
    }
    if (collisionCheckType != 3) {
        ret = didCollideWithBoundingBoxes(inVec, outCollision, g_UNK_StadiumDetails.pCollisionBoxes,
                                          g_UNK_StadiumDetails.numCollisionBoxes);
    }
end:
    return ret;
}

// .text:0x000008D4 size:0x40 mapped:0x8063F968
BALL_COLLISION_TYPE fn_3_8D4(VecSrcDst* inVec, CollisionStruct* outCollision) {
    if (g_UNK_StadiumDetails._778 != NULL) {
        return didCollideWithBoundingBoxes(inVec, outCollision, g_UNK_StadiumDetails._778, g_UNK_StadiumDetails._77C);
    }
    return BALL_COLLISION_TYPE_NONE;
}
