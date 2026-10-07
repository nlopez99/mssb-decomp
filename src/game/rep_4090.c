#include "game/rep_4090.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "Dolphin/rand.h"
#include "musyx/musyx.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct Particle4090 {
    /* 0x00 */ struct Particle4090* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ u8 _28[0x38 - 0x28];
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ u8 color[4];
    /* 0x44 */ u8 _44[0x48 - 0x44];
    /* 0x48 */ s16 _48;
    /* 0x4A */ s16 life;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
} Particle4090;

typedef struct Emitter4090 {
    /* 0x00 */ struct Emitter4090* prev;
    /* 0x04 */ struct Emitter4090* next;
    /* 0x08 */ BOOL (*update)(struct Emitter4090*);
    /* 0x0C */ Particle4090* particles;
    /* 0x10 */ void* _10;
    /* 0x14 */ u16 _14 : 4;
    /* 0x14 */ u16 count : 12;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18[0x60 - 0x18];
} Emitter4090;

// Particle settings
struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 life;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 fadeFrames;
    /* 0x10 */ s32 _10;
    /* 0x14 */ s32 scale;
    /* 0x18 */ s32 speed;
    /* 0x1C */ s32 riseSpeed;
    /* 0x20 */ s32 drag;
    /* 0x24 */ s32 gravity;
    /* 0x28 */ s32 _28;
    /* 0x2C */ s32 _2C;
    /* 0x30 */ s32 colorMin;
    /* 0x34 */ s32 colorRange;
    /* 0x38 */ s32 _38;
    /* 0x3C */ s32 _3C;
} lbl_3_data_2A408 = { 41, 120, 240, 40, 10, 80000, 10000, 15000, 10000, 300, 10, 60, 200, 55, 26, 0 };

typedef struct {
    /* 0x000 */ u8 _000[0x276];
    /* 0x276 */ u8 _276;
} UnkPlayer4090;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ UnkPlayer4090* _2C50[13];
} lbl_8036E548;

typedef struct {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 _0C[0x50 - 0x0C];
    /* 0x50 */ f32 _50;
    /* 0x54 */ u8 _54[0x268 - 0x54];
} UnkFielder4090;

extern UnkFielder4090 g_Fielders[9];

extern u16 lbl_3_data_81DC[16];
extern u8 lbl_3_data_8404[6][15][2];
extern u8 lbl_3_data_84B8[30][2];

extern void* lbl_803CBD0C;

extern BOOL fn_8001B728(s32, s32, Vec*);
extern Particle4090* fn_80031F34(Particle4090*, s32);
extern void fn_80033794(Particle4090*);
extern Emitter4090* fn_800337CC(Emitter4090*, s32, s32);
extern Emitter4090* fn_800339F0(Emitter4090*, s32);
extern Emitter4090* fn_80033A24(BOOL (*)(Emitter4090*), s32, s32, s32, s32, s32);
extern void fn_80033CC8(Particle4090*, void*);
extern void fn_80033F64(f32, f32, f32);
extern bool fn_800527C4(Vec*);

// .text:0x0016D5E4 size:0x22C mapped:0x807AC678
void fn_3_16D5E4(u8 fielder) {
    f32 height;
    Vec pos;

    if (g_d_GameSettings.StadiumID == STADIUM_ID_PEACH_GARDEN) {
        height = 1.5f;
    } else {
        height = 0.07f;
    }
    if (fielder != 0) {
        UnkFielder4090* data = &g_Fielders[fielder - 1];
        if (!fn_3_16D4D8(fielder - 1, height) || data->_50 < 0.1f) {
            return;
        }
        memcpy(&pos, data, sizeof(Vec));
        pos.y = height;
    } else {
        f32 speed = PSVECMag((Vec*)&g_Ball.physicsSubstruct.velocity);
        if (g_Ball.AtBat_Contact_BallPos.y <= height &&
            ((g_Ball.maybeCollisionRelated & 0x7F) != 9 || g_Ball.pastCoordinates[0].y > height) && speed >= 0.05) {
            memcpy(&pos, &g_Ball, sizeof(Vec));
        } else {
            return;
        }
    }
    if (fn_800527C4(&pos)) {
        fn_3_16CC2C(&pos, fielder);
    }
}

// .text:0x0016D4D8 size:0x10C mapped:0x807AC56C
bool fn_3_16D4D8(u8 player, f32 height) {
    Vec pos = { 0.0f, 0.0f, 0.0f };
    f32 bottom;

    if (lbl_8036E548._2C50[player]->_276 & 6) {
        return TRUE;
    }
    fn_8001B728(player, 35, &pos);
    bottom = -pos.y;
    pos.x = pos.y = pos.z = 0.0f;
    fn_8001B728(player, 31, &pos);
    if (height >= bottom | height >= -pos.y) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x0016CC2C size:0x8AC mapped:0x807ABCC0
void fn_3_16CC2C(Vec* pos, u8 fielder) {
    s32 n;
    Emitter4090* emitter;
    Emitter4090* added;
    Emitter4090 tmp;
    Particle4090* last;

    if (fielder != 0) {
        if (g_d_GameSettings.StadiumID == STADIUM_ID_PEACH_GARDEN) {
            n = 3;
        } else {
            n = 3;
        }
    } else {
        if (g_d_GameSettings.StadiumID == STADIUM_ID_PEACH_GARDEN) {
            n = 20;
        } else {
            n = 3;
        }
    }
    emitter = fn_800339F0(NULL, 26);
    if (emitter != NULL) {
        added = fn_800337CC(&tmp, n, 1);
        if (added == NULL) {
            return;
        }
        fn_3_16C878(pos, added, n);
        for (last = emitter->particles; last->next != NULL; last = last->next) {}
        last->next = added->particles;
        emitter->count += added->count;
    } else {
        emitter = fn_80033A24(fn_3_16C548, 0x80, 0, n, 1, 26);
        if (emitter != NULL) {
            emitter->count = n;
            fn_3_16C878(pos, emitter, n);
        } else {
            return;
        }
    }
    fn_3_16C410(fielder);
}

// .text:0x0016C878 size:0x3B4 mapped:0x807AB90C
void fn_3_16C878(Vec* pos, Emitter4090* emitter, s32 n) {
    Particle4090* p = emitter->particles;
    u32 i = 0;
    f32 angle;
    f32 speed;
    s32 shade;

    emitter->_10 = lbl_803CBD0C;
    for (; p != NULL; p = p->next) {
        p->_48 = 0;
        p->vel.y = lbl_3_data_2A408.riseSpeed / 100000.0f + (rand() % 100 - 50) / 1000.0;
        angle = MTXDegToRad(360.0 / n * i);
        speed = lbl_3_data_2A408.speed / 100000.0f + (rand() % 100 - 50) / 1000.0;
        p->vel.x = speed * COSF(angle);
        p->vel.z = speed * SINF(angle);
        p->_38 = p->_3C = lbl_3_data_2A408.scale / 100000.0f;
        p->pos.x = pos->x;
        p->pos.y = -pos->y;
        p->pos.z = pos->z;
        p->_1C = lbl_3_data_2A408._28 - (rand() % 5 + 1);
        p->_20 = 0.0f;
        p->_24 = lbl_3_data_2A408._2C - (rand() % 30 + 1);
        p->_48 = -(rand() % 2 * 2) + 1;
        shade = rand() % lbl_3_data_2A408.colorRange + 1;
        p->color[0] = p->color[1] = p->color[2] = lbl_3_data_2A408.colorMin + shade;
        p->color[3] = 255;
        p->life = lbl_3_data_2A408.life;
        p->_4D = lbl_3_data_2A408._00;
        p->_4E = 0;
        i++;
    }
}

// .text:0x0016C548 size:0x330 mapped:0x807AB5DC
BOOL fn_3_16C548(Emitter4090* emitter) {
    Particle4090* p;
    Particle4090** link;
    Particle4090* dead;
    Particle4090* last;
    s32 alive = 0;
    s32 alpha;

    p = emitter->particles = fn_80031F34(emitter->particles, emitter->count);
    link = &emitter->particles;
    last = NULL;
    dead = NULL;
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    do {
        if (p->life != 0) {
            fn_80033F64(p->_38, p->_3C, p->_20);
            fn_80033CC8(p, emitter->_10);
            if (p->life < lbl_3_data_2A408.fadeFrames) {
                alpha = p->color[3];
                alpha -= 255.0f / lbl_3_data_2A408.fadeFrames;
                if (alpha < 0) {
                    alpha = 0;
                }
                p->color[3] = alpha;
            }
            p->pos.x += p->vel.x;
            p->pos.y -= p->vel.y;
            p->pos.z += p->vel.z;
            if (p->pos.y > 0.0f) {
                p->pos.y = 0.0f;
            }
            p->vel.x -= p->vel.x * (lbl_3_data_2A408.drag / 100000.0f);
            p->vel.y -= p->vel.y * (lbl_3_data_2A408.drag / 100000.0f);
            p->vel.z -= p->vel.z * (lbl_3_data_2A408.drag / 100000.0f);
            p->vel.y -= lbl_3_data_2A408.gravity / 100000.0f;
            p->_20 += p->_1C * p->_48;
            if (p->_24 < p->_20 * p->_48) {
                p->_20 = p->_24 * p->_48;
                p->_48 *= -1;
            }
            p->life--;
            if (p->life == 0) {
                *link = p->next;
                if (last != NULL) {
                    last->next = p;
                } else {
                    dead = p;
                }
                last = p;
                p->next = NULL;
                emitter->count--;
            } else {
                link = &p->next;
                alive++;
            }
        }
    } while ((p = *link) != NULL);
    if (dead != NULL) {
        p = dead;
        do {
            p->_4C = 0;
            p->_48 = 0;
        } while ((p = p->next) != NULL);
        fn_80033794(dead);
    }
    return alive == 0;
}

// .text:0x0016C410 size:0x138 mapped:0x807AB4A4
void fn_3_16C410(u8 fielder) {
    u32 stadium;
    s32 sound;
    SND_VOICEID voice;
    u8 vol;

    if (fielder != 0) {
        if (g_d_GameSettings.StadiumID == STADIUM_ID_PEACH_GARDEN) {
            sound = 5;
        } else {
            sound = 14;
        }
    } else {
        if (g_d_GameSettings.StadiumID == STADIUM_ID_PEACH_GARDEN) {
            sound = 4;
        } else {
            sound = 13;
        }
    }
    stadium = g_d_GameSettings.StadiumID;
    if (stadium == STADIUM_ID_PEACH_GARDEN) {
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            vol = lbl_3_data_84B8[sound][0];
        } else {
            vol = lbl_3_data_8404[stadium][sound][0];
        }
        voice = sndFXStartEx(lbl_3_data_81DC[stadium] + sound, vol, 63, 0);
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
            vol = lbl_3_data_84B8[sound][1];
        } else {
            vol = lbl_3_data_8404[stadium][sound][1];
        }
        sndFXCtrl(voice, 91, vol);
    }
}
