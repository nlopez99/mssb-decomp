#include "static/static_800B0724.h"

// .text:0x800B0724 size:0xD8
void makeLookAtMatrix(Mtx m, Vec* camPos, Vec* camUp, Vec* target) {
    if (camPos->x == target->x && camPos->z == target->z) {
        m[0][0] = -1.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[0][3] = camPos->x;
        if (camPos->y - target->y <= 0.0f) {
            m[1][0] = 0.0f;
            m[1][1] = 0.0f;
            m[1][2] = -1.0f;
            m[1][3] = camPos->z;
            m[2][0] = 0.0f;
            m[2][1] = -1.0f;
            m[2][2] = 0.0f;
            m[2][3] = camPos->y;
        } else {
            m[1][0] = 0.0f;
            m[1][1] = 0.0f;
            m[1][2] = 1.0f;
            m[1][3] = -camPos->z;
            m[2][0] = 0.0f;
            m[2][1] = 1.0f;
            m[2][2] = 0.0f;
            m[2][3] = -camPos->y;
        }
    } else {
        C_MTXLookAt(m, camPos, camUp, target);
    }
}
