#include "game/rep_3AE8.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/rand.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0xC - 0x4];
    /* 0x0C */ s32 _0C;
    /* 0x10 */ u8 _10[0x38 - 0x10];
    /* 0x38 */ s32 _38;
    /* 0x3C */ s32 _3C;
    /* 0x40 */ u8 _40[0x48 - 0x40];
} Unk3AE8Trail; // size: 0x48

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ s32 _10;
    /* 0x14 */ u8 _14[0x84 - 0x14];
} Unk3AE8Arc; // size: 0x84

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ s32 _004;
    /* 0x008 */ u8 _008[0x464 - 0x8];
    /* 0x464 */ s16 _464;
} lbl_3_common_bss_35154;

// .data outside this unit's split
extern s16 lbl_3_data_5D6C[][7];
extern struct {
    /* 0x000 */ Unk3AE8Trail _000[2];
    /* 0x090 */ Unk3AE8Trail _090[2];
    /* 0x120 */ s32 _120;
} lbl_3_data_26F78;
extern Unk3AE8Arc lbl_3_data_2709C[2];

extern void fn_8002CDD0(Vec* pos);
extern void fn_8002CE4C(Vec* start, Vec* end, Unk3AE8Arc* arc);
extern void fn_8002DC68(Vec* pos);
extern void fn_8002DCE4(Vec* start, Vec* end, Unk3AE8Trail* trail);

// .text:0x0015C024 size:0x20C mapped:0x8079B0B8
void fn_3_15C024(Vec* pos, Vec* vel, Vec* accel, BOOL curve) {
    f32 dir = 0.0f;
    s16* entry = lbl_3_data_5D6C[g_Pitcher.specialPitchTypeCode];
    f32 z;
    f32 speed;
    u16 buttons;

    if (pos->z <= g_Pitcher.pitchZ_whenAirResistanceStarts) {
        z = vel->z - vel->z * g_Pitcher.airResistance_veloAdj;
        if (z < -0.05f) {
            vel->x -= vel->x * g_Pitcher.airResistance_veloAdj;
            vel->y -= vel->y * g_Pitcher.airResistance_veloAdj;
            vel->z = z;
        }
    }
    vel->x *= g_Pitcher.decelerationFactor;
    vel->y *= g_Pitcher.decelerationFactor;
    vel->z *= g_Pitcher.decelerationFactor;
    vel->x += accel->x;
    pos->x += vel->x;
    pos->y += vel->y;
    pos->z += vel->z;
    if (curve) {
        speed = 0.00005f * LinearInterpolateToNewRange(g_Pitcher.calced_curve, 1.0f, 100.0f, entry[1], entry[2]);
        buttons = g_Controls[g_GameLogic.teams[g_GameLogic.teamFielding]].buttonInput;
        if (buttons & INPUT_BUTTON_LEFT) {
            dir = -1.0f;
        } else if (buttons & INPUT_BUTTON_RIGHT) {
            dir = 1.0f;
        }
        if (dir) {
            vel->x = speed * dir;
        }
    }
}

// .text:0x0015C014 size:0x10 mapped:0x8079B0A8
s32 fn_3_15C014(void) {
    return lbl_3_data_2709C[0]._10;
}

// .text:0x0015C000 size:0x14 mapped:0x8079B094
void fn_3_15C000(void) {
    lbl_3_data_2709C[0]._10 = 2;
}

// .text:0x0015BAA0 size:0x560 mapped:0x8079AB34
// The original reads the .data at 0x26F78-0x271A8 as file statics from one pool base held in r31;
// these externs load each address separately. As statics (26F78[2], 27008[2], 27098, 2709C, 27120)
// every instruction matches.
void fn_3_15BAA0(BOOL which) {
    Vec pos;
    Vec vel;
    Vec accel;
    f32 limit;
    f32 min;
    f32 range;
    f32 t;
    s32 state;
    s32 i;

    if (g_GameLogic.bOD_framesInLiveBallScene >= 0) {
        state = 2;
    } else {
        state = g_Ball.framesSinceHit > 0;
    }

    switch (state) {
    case 0:
        if (lbl_3_common_bss_35154._464 == 0) {
            limit = lbl_3_data_26F78._000[which]._38 / 100000.0f;
            memcpy(&pos, &g_Pitcher.ballCurrentPosition, sizeof(Vec));
            memcpy(&vel, &g_Pitcher.ballVelocity, sizeof(Vec));
            memcpy(&accel, &g_Pitcher.pitchCurveVeloV1, sizeof(Vec));
            lbl_3_data_26F78._000[which]._0C = 0;
            while (pos.z > limit) {
                fn_3_15C024(&pos, &vel, &accel, FALSE);
                lbl_3_data_26F78._000[which]._0C++;
            }
            pos.y = -pos.y;
            vel.x = g_Pitcher.ballCurrentPosition.x;
            vel.y = -g_Pitcher.ballCurrentPosition.y;
            vel.z = g_Pitcher.ballCurrentPosition.z;
            if (which) {
                lbl_3_data_2709C[1]._00 = lbl_3_common_bss_35154._004;
                lbl_3_data_2709C[1]._10 = lbl_3_data_26F78._000[which]._0C;
                fn_8002CE4C(&vel, &pos, &lbl_3_data_2709C[1]);
            } else {
                lbl_3_data_26F78._000[which]._00 = lbl_3_common_bss_35154._004;
                fn_8002DCE4(&vel, &pos, &lbl_3_data_26F78._000[which]);
            }
        }
        break;
    case 1:
    case 2:
        if (which) {
            lbl_3_data_2709C[0]._00 = lbl_3_common_bss_35154._004;
            memcpy(&pos, &g_Ball.AtBat_Contact_BallPos, sizeof(Vec));
            i = 0;
            while (g_Ball.physicsSubstruct.futureCoordsAndDist[i + 1].pos.y >=
                   g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y) {
                i++;
            }
            limit = lbl_3_data_26F78._120 / 100000.0f;
            while (g_Ball.physicsSubstruct.futureCoordsAndDist[i + 1].pos.y >= limit) {
                i++;
            }
            lbl_3_data_2709C[0]._10 = i;
            memcpy(&vel, &g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos, sizeof(Vec));
            pos.y = -pos.y;
            vel.y = -vel.y;
            fn_8002CE4C(&pos, &vel, &lbl_3_data_2709C[0]);
        } else {
            lbl_3_data_26F78._090[which]._00 = lbl_3_common_bss_35154._004;
            i = 0;
            min = lbl_3_data_26F78._090[which]._38 / 100000.0f / 100.0f;
            range = lbl_3_data_26F78._090[which]._3C / 100000.0f / 100.0f - min;
            while (g_Ball.physicsSubstruct.futureCoordsAndDist[i].pos.y <
                   g_Ball.physicsSubstruct.futureCoordsAndDist[i + 1].pos.y) {
                i++;
            }
            t = min + range * rand() / 32767.0f;
            lbl_3_data_26F78._090[which]._0C = t * (g_Ball.hangtimeOfHit - i) + i;
            memcpy(&pos, &g_Ball.AtBat_Contact_BallPos, sizeof(Vec));
            memcpy(&vel, &g_Ball.physicsSubstruct.futureCoordsAndDist[lbl_3_data_26F78._090[which]._0C].pos,
                   sizeof(Vec));
            pos.y = -pos.y;
            vel.y = -vel.y;
            fn_8002DCE4(&pos, &vel, &lbl_3_data_26F78._090[which]);
        }
        break;
    }
}

// .text:0x0015B79C size:0x304 mapped:0x8079A830
void fn_3_15B79C(BOOL which) {
    Vec pos;
    Vec vel;
    Vec accel;
    f32 limit = lbl_3_data_26F78._000[which]._38 / 100000.0f;

    memcpy(&pos, &g_Pitcher.ballCurrentPosition, sizeof(Vec));
    memcpy(&vel, &g_Pitcher.ballVelocity, sizeof(Vec));
    memcpy(&accel, &g_Pitcher.pitchCurveVeloV1, sizeof(Vec));
    while (pos.z > limit) {
        fn_3_15C024(&pos, &vel, &accel, TRUE);
    }
    pos.y = -pos.y;
    if (which) {
        fn_8002CDD0(&pos);
    } else {
        fn_8002DC68(&pos);
    }
}
