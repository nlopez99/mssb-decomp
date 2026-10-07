#include "game/rep_3880.h"
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "Dolphin/gx.h"
#include "Dolphin/mtx.h"
#include "C3/control.h"
#include "Dolphin/rand.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u8 _00[0xEC];
    /* 0xEC */ Mtx* _EC;
} UnkModel3880;

typedef struct {
    /* 0x00 */ u8 _00[0x18];
    /* 0x18 */ UnkModel3880** _18;
} UnkModelSet3880;

typedef struct Particle3880 {
    /* 0x00 */ struct Particle3880* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec vel;
    /* 0x1C */ Vec _1C;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ f32 _30;
    /* 0x34 */ f32 _34;
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ u8 color[4];
    /* 0x44 */ u8 _44;
    /* 0x45 */ u8 _45;
    /* 0x46 */ u8 _46;
    /* 0x47 */ u8 _47;
    /* 0x48 */ s16 _48;
    /* 0x4A */ s16 _4A;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 _4F;
} Particle3880;

// Particles of emitter 0x27
typedef struct Particle27_3880 {
    /* 0x00 */ struct Particle27_3880* next;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec* origin;
    /* 0x14 */ Vec* rotation;
    /* 0x18 */ s16 id;
    /* 0x1A */ u8 _1A[0x38 - 0x1A];
    /* 0x38 */ f32 _38;
    /* 0x3C */ f32 _3C;
    /* 0x40 */ u8 color[4];
    /* 0x44 */ u8 _44[0x48 - 0x44];
    /* 0x48 */ s16 _48;
    /* 0x4A */ s16 _4A;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 _4F;
} Particle27_3880;

// Particles of the trail emitter in lbl_3_bss_B850
typedef struct TrailNode3880 {
    /* 0x00 */ struct TrailNode3880* next;
    /* 0x04 */ Vec points[7];
} TrailNode3880;

typedef struct Emitter3880 {
    /* 0x00 */ struct Emitter3880* prev;
    /* 0x04 */ struct Emitter3880* next;
    /* 0x08 */ BOOL (*update)(struct Emitter3880*);
    /* 0x0C */ Particle3880* particles;
    /* 0x10 */ void* _10;
    /* 0x14 */ u16 _14 : 4;
    /* 0x14 */ u16 count : 12;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
} Emitter3880; // size: 0x18, followed by each effect's own fields

// A whole emitter slot, for a list built on the stack
typedef struct {
    /* 0x00 */ Emitter3880 base;
    /* 0x18 */ u8 _18[0x60 - 0x18];
} EmitterSlot3880;

typedef struct TrailEmitter3880 {
    /* 0x00 */ Emitter3880 base;
    /* 0x18 */ u8 _18;
} TrailEmitter3880;

typedef struct PlayerEmitter3880 {
    /* 0x00 */ Emitter3880 base;
    /* 0x18 */ s8 player;
} PlayerEmitter3880;

typedef struct ModelEmitter3880 {
    /* 0x00 */ Emitter3880 base;
    /* 0x18 */ UnkModelSet3880** models;
    /* 0x1C */ Vec pos;
} ModelEmitter3880;

typedef struct PathEmitter3880 {
    /* 0x00 */ Emitter3880 base;
    /* 0x18 */ Vec _18;
    /* 0x24 */ Vec _24;
    /* 0x30 */ f32 _30;
    /* 0x34 */ s16 _34;
    /* 0x36 */ s16 _36;
} PathEmitter3880;


typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ UnkModelSet3880* _34;
    /* 0x38 */ u8 _38[0x90 - 0x38];
} UnkActor3880; // size: 0x90

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ Vec _34;
} UnkPlayer3880;

extern struct {
    /* 0x0000 */ u8 _0000[0x68];
    /* 0x0068 */ UnkActor3880* _0068;
    /* 0x006C */ u8 _006C[0x2C50 - 0x6C];
    /* 0x2C50 */ UnkPlayer3880* _2C50[13];
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0x6C];
    /* 0x6C */ void* _6C;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern s32 lbl_3_data_26C94[9];
extern s32 lbl_3_data_26E7C[8];
extern s32 lbl_3_data_26E40[15];
extern s32 lbl_3_data_26D00[20];
extern s32 lbl_3_data_26CD0[12];
extern s32 lbl_3_data_26C3C[22];
extern f32 lbl_3_data_26C1C[4][2];
extern Vec lbl_3_data_26E00[3];
extern s32 lbl_3_data_26E24[7];
extern f32 lbl_3_data_21770[6];
extern u8 lbl_3_data_26CB8[24];
extern Vec lbl_3_data_26D50;
extern s32 lbl_3_data_26BDC[4];
extern Vec lbl_3_data_26BB4;
extern s32 lbl_3_data_26BC0[7];
extern s32 lbl_3_data_26BEC[4];
extern s32 lbl_3_data_26BFC[4];
extern s32 lbl_3_data_26C0C[4];
extern s32 lbl_3_data_26D5C[11];
extern s32 lbl_3_data_26D88[15];
extern s32 lbl_3_data_26DC4[15];

extern BOOL fn_8001B728(s32, s32, Vec*);
extern s32 fn_8005268C(void);
extern camera_803c639c_s* fn_80052734(s32 index);
extern Particle3880* fn_80031F34(Particle3880* particles, s32 count);
extern void fn_80033794(void* particles);
extern void fn_80033B58(void* texture, s32 index, s32, s32);
extern void pitchingMachinePitching(u8 id);
extern void fn_80033620(Emitter3880* emitter);
extern void fn_80033CC8(Particle3880* p, void* texture);
extern void fn_80033F64(f32 width, f32 height, f32 angle);
extern void fn_8003403C(f32 width, f32 height);
extern Emitter3880* fn_800339F0(Emitter3880* start, u8 id);
extern Emitter3880* fn_800337CC(Emitter3880* emitter, s32 count, s32 exact);
extern Emitter3880* fn_80033A24(BOOL (*update)(Emitter3880*), s32, s32, s32, s32, s32);

// .bss, declared in reverse address order: MWCC lays statics out last to first
// rep_3310.h declares these as void(void) placeholders
extern f32 fn_3_119854(u8 index);
extern f32 fn_3_119D28(void);

// rep_3448.h declares this as a void(void) placeholder
extern void fn_3_11F4B4(s32 player, BOOL flag);

static u8 lbl_3_bss_B894[0x124];
static u8 lbl_3_bss_B890[4]; // unreferenced
static Vec lbl_3_bss_B860[4];
static s8 lbl_3_bss_B85C[4];
static u8 lbl_3_bss_B858;
static s32 lbl_3_bss_B854;
static TrailEmitter3880* lbl_3_bss_B850;

// .text:0x00157AC4 size:0x2F4 mapped:0x80796B58
void fn_3_157AC4(void) {
    return;
}

// .text:0x0015791C size:0x1A8 mapped:0x807969B0
f32 fn_3_15791C(s32 frame) {
    s32 cycles = (frame + 48) / 120;
    s32 phase = (frame + 48) % 120;
    f32 c;
    f32 scale;

    if (phase >= 48) {
        c = cos(3.1415927f * (1.0f + (phase - 48.0f) / 72.0f));
    } else {
        c = cos(3.1415927f * (phase / 48.0f));
    }
    scale = c / 2;
    scale += 0.5f;
    if (cycles != 0 && g_GameLogic.gameStatus != GAME_STATUS_MVP_END_GAME &&
        g_GameLogic.gameStatus != GAME_STATUS_MINIGAME_POST_MENU && g_GameLogic.gameStatus != GAME_STATUS_0x24 &&
        g_GameLogic.gameStatus != GAME_STATUS_0x26) {
        scale += 0.5f * (frame - 72.0f) / 120.0f;
    }
    return 4.0f * scale;
}

// .text:0x001578F8 size:0x24 mapped:0x8079698C
void fn_3_1578F8(void) {
    pitchingMachinePitching(0x16);
}

// .text:0x0015767C size:0x27C mapped:0x80796710
BOOL fn_3_15767C(Emitter3880* emitter) {
    return 0;
}

// .text:0x001575F0 size:0x8C mapped:0x80796684
Vec* fn_3_1575F0(u32 index) {
    TrailNode3880* node;

    if (lbl_3_bss_B850 != NULL) {
        node = (TrailNode3880*)lbl_3_bss_B850->base.particles;
        while (index >= 7) {
            node = node->next;
            index -= 7;
        }
        return &node->points[index];
    }
    return NULL;
}

// .text:0x00157588 size:0x68 mapped:0x8079661C
void fn_3_157588(s32 count) {
    lbl_3_bss_B850 = (TrailEmitter3880*)fn_80033A24(fn_3_15767C, 0x80, 0, (count + 6) / 7, 1, 0x28);
    lbl_3_bss_B850->_18 = 0;
}

// .text:0x00157570 size:0x18 mapped:0x80796604
void fn_3_157570(void) {
    lbl_3_bss_B850->_18 = 1;
}

// .text:0x001573AC size:0x1C4 mapped:0x80796440
void fn_3_1573AC(void) {
    return;
}

// .text:0x0015730C size:0xA0 mapped:0x807963A0
void fn_3_15730C(u32 index, f32 x, f32 y, f32 z) {
    Vec* point = fn_3_1575F0(index);

    if (point != NULL) {
        point->x = x;
        point->y = y;
        point->z = z;
    }
}

// .text:0x00156D04 size:0x608 mapped:0x80795D98
void fn_3_156D04(void) {
    return;
}

// .text:0x00156970 size:0x394 mapped:0x80795A04
void fn_3_156970(void) {
    return;
}

// .text:0x00156548 size:0x428 mapped:0x807955DC
void fn_3_156548(void) {
    return;
}

// .text:0x00156218 size:0x330 mapped:0x807952AC
// Differs only through fn_3_155F08's call to fn_3_155C28, which the target inlines.
void fn_3_156218(void) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES &&
        g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY) {
        fn_3_155F08();
    }
}

// .text:0x00155F08 size:0x310 mapped:0x80794F9C
// The target inlines fn_3_155C28 here (99.8% with it marked inline, which drops its
// standalone copy); MWCC keeps this version's call out of line.
void fn_3_155F08(void) {
    Emitter3880* emitter = fn_80033A24(fn_3_1552AC, 0x80, 0, lbl_3_data_26BC0[1], 1, 0x1B);

    if (emitter != NULL) {
        fn_3_155C28(emitter);
    }
}

// .text:0x00155C28 size:0x2E0 mapped:0x80794CBC
void fn_3_155C28(Emitter3880* emitter) {
    Particle3880* p;
    u32 i;
    Control control;
    Mtx mtx;
    Vec base;
    Vec v;
    f64 height;
    f32 rx;
    f32 ry;
    f32 rz;

    p = emitter->particles;
    emitter->_10 = lbl_3_common_bss_32724._6C;
    i = 0;
    do {
        p->_48 = (u8)i++;
        p->_4D = lbl_3_data_26BC0[0];
        p->_4E = 0;
        if (p->_48 == 0) {
            rx = 57.29578f * shortAngleToRad(g_Ball.matchFramesAndBallAngle.ballSpinAngle.yaw);
            ry = 57.29578f * shortAngleToRad(g_Ball.matchFramesAndBallAngle.ballSpinAngle.pitch);
            rz = 57.29578f * shortAngleToRad(g_Ball.matchFramesAndBallAngle.ballSpinAngle.roll);
            p->_4A = lbl_3_data_26BC0[6];
            control.type = 0;
            CTRLSetRotation(&control, rx, ry, rz);
            CTRLBuildMatrix(&control, mtx);
            if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY) {
                base = lbl_3_data_26BB4;
            } else {
                PSVECScale(&lbl_3_data_26BB4, 1.5f, &base);
            }
            v.x = base.x + 1.5 * ((rand() % 40 - 20) / 100.0);
            v.y = base.y;
            v.z = base.z + 1.5 * ((rand() % 40 - 20) / 100.0);
            PSMTXMultVec(mtx, &v, &v);
            v.x += g_Ball.AtBat_Contact_BallPos.x;
            height = fabs(g_Ball.AtBat_Contact_BallPos.y);
            v.y -= height;
            v.z += g_Ball.AtBat_Contact_BallPos.z;
            p->pos.x = v.x;
            p->pos.y = v.y;
            p->pos.z = v.z;
            p->_3C = p->_38 = lbl_3_data_26BC0[2];
            p->color[3] = lbl_3_data_26BC0[4];
        }
        p = p->next;
    } while (p != NULL);
}

// .text:0x001559E4 size:0x244 mapped:0x80794A78
void fn_3_1559E4(Particle27_3880* p, Vec* pos, Vec* rot) {
    Control control;
    Mtx mtx;
    Vec v;
    Vec base;
    f64 height;

    p->_4A = lbl_3_data_26BC0[6];
    control.type = 0;
    CTRLSetRotation(&control, rot->x, rot->y, rot->z);
    CTRLBuildMatrix(&control, mtx);
    if (g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BOBOMB_DERBY) {
        base = lbl_3_data_26BB4;
    } else {
        PSVECScale(&lbl_3_data_26BB4, 1.5f, &base);
    }
    v.x = base.x + 1.5 * ((rand() % 40 - 20) / 100.0);
    v.y = base.y;
    v.z = base.z + 1.5 * ((rand() % 40 - 20) / 100.0);
    PSMTXMultVec(mtx, &v, &v);
    v.x += pos->x;
    height = fabs(pos->y);
    v.y -= height;
    v.z += pos->z;
    p->pos.x = v.x;
    p->pos.y = v.y;
    p->pos.z = v.z;
    p->_3C = p->_38 = lbl_3_data_26BC0[2];
    p->color[3] = lbl_3_data_26BC0[4];
}

// .text:0x001552AC size:0x738 mapped:0x80794340
BOOL fn_3_1552AC(Emitter3880* emitter) {
    return 0;
}

// .text:0x00155288 size:0x24 mapped:0x8079431C
void fn_3_155288(void) {
    pitchingMachinePitching(0x1B);
}

// .text:0x00155264 size:0x24 mapped:0x807942F8
void fn_3_155264(void) {
    pitchingMachinePitching(0x1B);
}

// .text:0x0015521C size:0x48 mapped:0x807942B0
void fn_3_15521C(s16 id, Vec* pos, Vec* rot) {
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES || pos == NULL || rot == NULL) {
        return;
    }
    fn_3_154C7C(id, pos, rot);
}

// .text:0x00154C7C size:0x5A0 mapped:0x80793D10
void fn_3_154C7C(s16 id, Vec* pos, Vec* rot) {
    EmitterSlot3880 tmp;
    Emitter3880* emitter;
    Emitter3880* added;
    Particle3880* last;

    emitter = fn_800339F0(NULL, 0x27);
    if (emitter != NULL) {
        added = fn_800337CC(&tmp.base, lbl_3_data_26BC0[1], 1);
        if (added == NULL) {
            return;
        }
        fn_3_1549F0(added, id, pos, rot);
        last = emitter->particles;
        if (last != NULL) {
            for (; last->next != NULL; last = last->next) {}
            last->next = added->particles;
        } else {
            emitter->particles = added->particles;
        }
        emitter->count += added->count;
    } else {
        emitter = fn_80033A24(fn_3_1542F4, 0x80, 0, lbl_3_data_26BC0[1], 1, 0x27);
        if (emitter != NULL) {
            fn_3_1549F0(emitter, id, pos, rot);
        }
    }
}

// .text:0x001549F0 size:0x28C mapped:0x80793A84
void fn_3_1549F0(Emitter3880* emitter, s16 id, Vec* pos, Vec* rot) {
    Particle27_3880* p;
    u32 i;

    i = 0;
    p = (Particle27_3880*)emitter->particles;
    emitter->_10 = lbl_3_common_bss_32724._6C;
    do {
        p->id = id;
        p->origin = pos;
        p->rotation = rot;
        p->_48 = (u8)i++;
        p->_4D = lbl_3_data_26BC0[0];
        p->_4E = 0;
        if (p->_48 == 0) {
            fn_3_1559E4(p, pos, rot);
        }
        p = p->next;
    } while (p != NULL);
}

// .text:0x001542F4 size:0x6FC mapped:0x80793388
BOOL fn_3_1542F4(Emitter3880* emitter) {
    return 0;
}

// .text:0x00154238 size:0xBC mapped:0x807932CC
void fn_3_154238(s16 id) {
    Emitter3880* emitter = fn_800339F0(NULL, 0x27);
    Particle27_3880** link;
    Particle27_3880* p;
    Particle27_3880* removed;
    Particle27_3880* last;

    if (emitter != NULL) {
        p = (Particle27_3880*)emitter->particles;
        link = (Particle27_3880**)&emitter->particles;
        last = NULL;
        removed = NULL;
        do {
            if (p->id == id) {
                *link = p->next;
                if (last != NULL) {
                    last->next = p;
                } else {
                    removed = p;
                }
                p->next = NULL;
                last = p;
                emitter->count--;
            } else {
                link = &p->next;
            }
        } while ((p = *link) != NULL);
        if (removed != NULL) {
            fn_80033794(removed);
        }
    }
}

// .text:0x00154214 size:0x24 mapped:0x807932A8
void fn_3_154214(void) {
    pitchingMachinePitching(0x27);
}

// .text:0x001541C4 size:0x50 mapped:0x80793258
void fn_3_1541C4(void) {
    return;
}

// .text:0x001540E4 size:0xE0 mapped:0x80793178
void fn_3_1540E4(void) {
    return;
}

// .text:0x00153F8C size:0x158 mapped:0x80793020
void fn_3_153F8C(void) {
    return;
}

// .text:0x00153E8C size:0x100 mapped:0x80792F20
void fn_3_153E8C(Particle3880* p, Vec* pos, u8 arg2, u8 arg3, u8 arg4) {
    p->_48 = (arg4 != 0) * lbl_3_data_26BEC[3] + arg4 * lbl_3_data_26BDC[3] / lbl_3_data_26BDC[0];
    p->_4D = arg3 == 4;
    p->_4E = 0;
    p->_4F = arg2;
    p->color[0] = p->color[1] = p->color[2] = 0xFF;
    p->color[3] = lbl_3_data_26BDC[1];
    p->_1C.x = pos->x;
    p->_1C.y = -pos->y - 0.1435f * (p->_4D ? fn_3_119854(2) : fn_3_119854(0));
    p->_1C.z = pos->z;
    p->_44 = p->_45 = 0;
}

// .text:0x001536A8 size:0x7E4 mapped:0x8079273C
void fn_3_1536A8(void) {
    return;
}

// .text:0x001534C0 size:0x1E8 mapped:0x80792554
void fn_3_1534C0(Particle3880* p) {
    Mtx rot;
    camera_803c639c_s* camera = fn_80052734(fn_8005268C());
    f32 height = p->_4D ? fn_3_119854(2) : fn_3_119854(0);
    Vec forward = { 0.0f, 0.0f, -1.0f };
    Vec axis;
    Vec dir;
    Vec offset;
    f32 angle;

    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = -0.354f * height;
    PSVECSubtract(&camera->eye, &p->_1C, &dir);
    PSVECNormalize(&dir, &dir);
    angle = acos(PSVECDotProduct(&forward, &dir));
    PSVECCrossProduct(&forward, &dir, &axis);
    if (PSVECMag(&axis) == 0.0f) {
        axis.x = 0.0f;
        axis.y = -1.0f;
        axis.z = 0.0f;
    }
    PSMTXRotAxisRad(rot, &axis, angle);
    PSMTXMultVec(rot, &offset, &offset);
    p->pos.x = p->_1C.x + offset.x;
    p->pos.y = p->_1C.y + offset.y;
    p->pos.z = p->_1C.z + offset.z;
    p->_38 = p->_3C = lbl_3_data_26BEC[0];
    p->_4C = 1;
    p->_4A = lbl_3_data_26BEC[3];
    p->vel.x = p->vel.z = 0.0f;
    p->vel.y = lbl_3_data_26BEC[2] / 100000.0f;
}

// .text:0x001531A4 size:0x31C mapped:0x80792238
void fn_3_1531A4(Particle3880* p) {
    Mtx rot;
    camera_803c639c_s* camera = fn_80052734(fn_8005268C());
    f32 height = p->_4D ? fn_3_119854(2) : fn_3_119854(0);
    Vec forward = { 0.0f, 0.0f, -1.0f };
    Vec axis;
    Vec dir;
    Vec offset;
    f32 angle;

    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = -0.354f * height;
    offset.x += height * ((rand() % 50 - 25) / 100.0);
    offset.y += height * ((rand() % 50 - 25) / 100.0);
    offset.z += height * ((rand() % 50 - 25) / 100.0);
    PSVECSubtract(&camera->eye, &p->_1C, &dir);
    PSVECNormalize(&dir, &dir);
    angle = acos(PSVECDotProduct(&forward, &dir));
    PSVECCrossProduct(&forward, &dir, &axis);
    if (PSVECMag(&axis) == 0.0f) {
        axis.x = 0.0f;
        axis.y = -1.0f;
        axis.z = 0.0f;
    }
    PSMTXRotAxisRad(rot, &axis, angle);
    PSMTXMultVec(rot, &offset, &offset);
    p->pos.x = p->_1C.x + offset.x;
    p->pos.y = p->_1C.y + offset.y;
    p->pos.z = p->_1C.z + offset.z;
    p->_38 = p->_3C = lbl_3_data_26BFC[0];
    p->_4C = 2;
    p->_4A = lbl_3_data_26BFC[3];
    p->vel.x = p->vel.z = 0.0f;
    p->vel.y = lbl_3_data_26BFC[2] / 100000.0f;
}

// .text:0x00152AB4 size:0x6F0 mapped:0x80791B48
void fn_3_152AB4(void) {
    return;
}

// .text:0x00152794 size:0x320 mapped:0x80791828
void fn_3_152794(Particle3880* p) {
    Mtx rot;
    camera_803c639c_s* camera = fn_80052734(fn_8005268C());
    f32 height = p->_4D ? fn_3_119854(2) : fn_3_119854(0);
    Vec forward = { 0.0f, 0.0f, -1.0f };
    Vec axis;
    Vec dir;
    Vec offset;
    f32 angle;

    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = -0.354f * height;
    offset.x += height * ((rand() % 50 - 25) / 100.0);
    offset.y += height * ((rand() % 50 - 25) / 100.0);
    offset.z += height * ((rand() % 50 - 25) / 100.0);
    PSVECSubtract(&camera->eye, &p->_1C, &dir);
    PSVECNormalize(&dir, &dir);
    angle = acos(PSVECDotProduct(&forward, &dir));
    PSVECCrossProduct(&forward, &dir, &axis);
    if (PSVECMag(&axis) == 0.0f) {
        axis.x = 0.0f;
        axis.y = -1.0f;
        axis.z = 0.0f;
    }
    PSMTXRotAxisRad(rot, &axis, angle);
    PSMTXMultVec(rot, &offset, &offset);
    p->pos.x = p->_1C.x + offset.x;
    p->pos.y = p->_1C.y + offset.y;
    p->pos.z = p->_1C.z + offset.z;
    p->_38 = p->_3C = lbl_3_data_26C0C[0];
    p->_4C = 3;
    p->_4A = lbl_3_data_26C0C[3];
    p->vel.x = p->vel.z = 0.0f;
    p->vel.y = -(lbl_3_data_26C0C[2] / 100000.0f);
}

// .text:0x001524E8 size:0x2AC mapped:0x8079157C
void fn_3_1524E8(Particle3880* p, u8 jitter) {
    Mtx rot;
    Vec offset;
    Vec dir;
    Vec axis;
    camera_803c639c_s* camera = fn_80052734(fn_8005268C());
    f32 height = p->_4D ? fn_3_119854(2) : fn_3_119854(0);
    Vec forward = { 0.0f, 0.0f, -1.0f };
    f32 angle;

    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = -0.354f * height;
    if (jitter) {
        offset.x += height * ((rand() % 50 - 25) / 100.0);
        offset.y += height * ((rand() % 50 - 25) / 100.0);
        offset.z += height * ((rand() % 50 - 25) / 100.0);
    }
    PSVECSubtract(&camera->eye, &p->_1C, &dir);
    PSVECNormalize(&dir, &dir);
    angle = acos(PSVECDotProduct(&forward, &dir));
    PSVECCrossProduct(&forward, &dir, &axis);
    if (PSVECMag(&axis) == 0.0f) {
        axis.x = 0.0f;
        axis.y = -1.0f;
        axis.z = 0.0f;
    }
    PSMTXRotAxisRad(rot, &axis, angle);
    PSMTXMultVec(rot, &offset, &offset);
    p->pos.x = p->_1C.x + offset.x;
    p->pos.y = p->_1C.y + offset.y;
    p->pos.z = p->_1C.z + offset.z;
}

// .text:0x00151F2C size:0x5BC mapped:0x80790FC0
void fn_3_151F2C(void) {
    return;
}

// .text:0x00151D6C size:0x1C0 mapped:0x80790E00
void fn_3_151D6C(Emitter3880* emitter, Particle3880* p) {
    f32 height;
    s32 alpha;
    s32 step;
    f32 grow;

    fn_8003403C(p->_38, p->_3C);
    fn_80033CC8(p, emitter->_10);
    height = p->_4D ? fn_3_119854(2) : fn_3_119854(0);
    alpha = p->color[3];
    if (lbl_3_data_26BEC[3] / p->_4A < 2) {
        step = lbl_3_data_26BDC[2] / (lbl_3_data_26BEC[3] / 2);
        grow = lbl_3_data_26BEC[1] * height / 100000.0f / (lbl_3_data_26BEC[3] / 2);
    } else {
        step = -lbl_3_data_26BDC[2] / (lbl_3_data_26BEC[3] / 2);
        grow = -(lbl_3_data_26BEC[1] * height / 100000.0f) / (lbl_3_data_26BEC[3] / 2);
    }
    alpha += step;
    if (alpha < 0) {
        alpha = 0;
    } else if (alpha > 255) {
        alpha = 255;
    }
    p->color[3] = alpha;
    p->_38 += grow;
    p->_3C = p->_38;
    PSVECAdd(&p->pos, &p->vel, &p->pos);
    p->_4A--;
}

// .text:0x00151BAC size:0x1C0 mapped:0x80790C40
void fn_3_151BAC(Emitter3880* emitter, Particle3880* p) {
    f32 height;
    s32 alpha;
    s32 step;
    f32 grow;

    fn_8003403C(p->_38, p->_3C);
    fn_80033CC8(p, emitter->_10);
    height = p->_4D ? fn_3_119854(2) : fn_3_119854(0);
    alpha = p->color[3];
    if (lbl_3_data_26BFC[3] / p->_4A < 2) {
        step = lbl_3_data_26BDC[2] / (lbl_3_data_26BFC[3] / 2);
        grow = lbl_3_data_26BFC[1] * height / 100000.0f / (lbl_3_data_26BFC[3] / 2);
    } else {
        step = -lbl_3_data_26BDC[2] / (lbl_3_data_26BFC[3] / 2);
        grow = -(lbl_3_data_26BFC[1] * height / 100000.0f) / (lbl_3_data_26BFC[3] / 2);
    }
    alpha += step;
    if (alpha < 0) {
        alpha = 0;
    } else if (alpha > 255) {
        alpha = 255;
    }
    p->color[3] = alpha;
    p->_38 += grow;
    p->_3C = p->_38;
    PSVECAdd(&p->pos, &p->vel, &p->pos);
    p->_4A--;
}

// .text:0x001519F8 size:0x1B4 mapped:0x80790A8C
void fn_3_1519F8(Emitter3880* emitter, Particle3880* p) {
    Vec pull;
    Vec dir;
    Vec target;
    f32 dist;

    fn_3_1517D0(p, emitter);
    if (lbl_80366158._28 == 0) {
        PSVECAdd(&p->pos, &p->vel, &p->pos);
        memcpy(&pull, &p->pos, sizeof(Vec));
        pull.x = lbl_3_data_26C1C[p->_44][0] - pull.x;
        pull.y = lbl_3_data_26C1C[p->_44][1] - pull.y;
        pull.z = 0.0f;
        PSVECNormalize(&pull, &dir);
        dist = PSVECMag(&pull);
        PSVECScale(&dir, 0.0015f * (1.0f / (dist * dist)), &pull);
        PSVECAdd(&p->vel, &pull, &p->vel);
        target.x = lbl_3_data_26C1C[p->_44][0];
        target.y = lbl_3_data_26C1C[p->_44][1];
        target.z = 0.0f;
        PSVECNormalize(&target, &target);
        if (PSVECDotProduct(&dir, &target) < 0.0f || !dist) {
            p->_4A = 0;
        }
        if (p->_4A == 0 && p->_45 != 0) {
            fn_3_11F4B4(p->_44, p->_4D == 1);
            p->_45 = 0;
        }
    }
}

// .text:0x001517D0 size:0x228 mapped:0x80790864
void fn_3_1517D0(Particle3880* p, Emitter3880* emitter) {
    f32 halfW = p->_38 / 2;
    f32 halfH = p->_3C / 2;
    Mtx mv;
    Mtx44 proj;
    Vec quad[4];
    f32 uv[4][2] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
    s32 i;

    quad[0].x = -halfW;
    quad[0].y = -halfH;
    quad[1].x = halfW;
    quad[1].y = -halfH;
    quad[2].x = halfW;
    quad[2].y = halfH;
    quad[3].x = -halfW;
    quad[3].y = halfH;
    quad[3].z = 0.0f;
    quad[2].z = 0.0f;
    quad[1].z = 0.0f;
    quad[0].z = 0.0f;
    PSMTXIdentity(mv);
    PSMTX44Identity(proj);
    GXLoadPosMtxImm(mv, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetProjection(proj, GX_PERSPECTIVE);
    fn_80033B58(emitter->_10, p->_4D, 0, 0);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    for (i = 0; i < 4; i++) {
        GXPosition3f32(p->pos.x + quad[i].x, p->pos.y + quad[i].y, -1.0f);
        GXColor1u32(*(u32*)p->color);
        GXTexCoord2f32(uv[p->_4E + i][0], uv[p->_4E + i][1]);
    }
    GXLoadPosMtxImm(fn_80052768_getCamera(0)->view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetProjection(fn_80052768_getCamera(0)->proj, GX_PERSPECTIVE);
}

// .text:0x00151798 size:0x38 mapped:0x8079082C
void fn_3_151798(void) {
    memset(lbl_3_bss_B894, 0, 0xF);
    pitchingMachinePitching(0x1C);
}

// .text:0x00151760 size:0x38 mapped:0x807907F4
void fn_3_151760(void) {
    memset(lbl_3_bss_B894, 0, 0xF);
    pitchingMachinePitching(0x1C);
}

// .text:0x00151710 size:0x50 mapped:0x807907A4
void fn_3_151710(void) {
    return;
}

// .text:0x00151694 size:0x7C mapped:0x80790728
void fn_3_151694(void) {
    return;
}

// .text:0x00151204 size:0x490 mapped:0x80790298
void fn_3_151204(void) {
    return;
}

// .text:0x00151068 size:0x19C mapped:0x807900FC
void fn_3_151068(ModelEmitter3880* emitter, Particle3880* p) {
    UnkModel3880* model;
    Mtx mtx;
    f32 x;
    f32 y;
    f32 z;

    p->_4A = lbl_3_data_26C3C[6];
    model = (*emitter->models)->_18[lbl_3_data_26C3C[7]];
    PSMTXIdentity(mtx);
    x = (*model->_EC)[0][3];
    y = (*model->_EC)[1][3];
    z = (*model->_EC)[2][3];
    x += (rand() % 100 - 50) / 100.0;
    y += (rand() % 150 - 75) / 100.0;
    p->pos.x = x;
    p->pos.y = y;
    p->pos.z = z;
    p->_3C = p->_38 = lbl_3_data_26C3C[2];
    p->color[3] = lbl_3_data_26C3C[4];
}

// .text:0x00150D84 size:0x2E4 mapped:0x8078FE18
// 82.56%: the target keeps lbl_3_data_26C3C's address in a saved register across each
// rand() and forms it again for the next range; here it is formed after the call.
void fn_3_150D84(ModelEmitter3880* emitter, Particle3880* p) {
    f32 deg;
    f32 angle;
    f32 speed;

    p->_4A = lbl_3_data_26C3C[20];
    p->pos.x = emitter->pos.x;
    p->pos.y = -emitter->pos.y;
    p->pos.z = emitter->pos.z;
    p->_38 = p->_3C = (lbl_3_data_26C3C[10] + rand() % (lbl_3_data_26C3C[11] - lbl_3_data_26C3C[10])) / 100000.0f;
    p->vel.y = (lbl_3_data_26C3C[12] + rand() % (lbl_3_data_26C3C[13] - lbl_3_data_26C3C[12])) / 100000.0f;
    deg = (rand() % 36000) / 100.0;
    angle = 0.017453292f * deg;
    speed = (lbl_3_data_26C3C[16] + rand() % (lbl_3_data_26C3C[17] - lbl_3_data_26C3C[16])) / 100000.0f;
    p->vel.x = speed * cosf_kludge(angle);
    p->vel.z = speed * sinf_kludge(angle);
    p->_1C.x = 57.29578f * ((lbl_3_data_26C3C[18] + rand() % (lbl_3_data_26C3C[19] - lbl_3_data_26C3C[18])) / 100000.0f);
    p->_1C.x *= (rand() % 2) * -2 + 1;
    p->color[0] = p->color[1] = p->color[2] = p->color[3] = 0xFF;
}

// .text:0x00150940 size:0x444 mapped:0x8078F9D4
void fn_3_150940(void) {
    return;
}

// .text:0x001504EC size:0x454 mapped:0x8078F580
void fn_3_1504EC(void) {
    return;
}

// .text:0x00150120 size:0x3CC mapped:0x8078F1B4
void fn_3_150120(void) {
    return;
}

// .text:0x001500C8 size:0x58 mapped:0x8078F15C
void fn_3_1500C8(void) {
    Emitter3880* emitter = fn_800339F0(NULL, 0x1D);
    Particle3880* p;

    if (emitter != NULL) {
        p = emitter->particles;
        do {
            p->_4A = 0;
            p->_48 = 0;
            p->_4C = 0;
            p = p->next;
        } while (p != NULL);
    }
    pitchingMachinePitching(0x1D);
}

// .text:0x00150070 size:0x58 mapped:0x8078F104
void fn_3_150070(void) {
    Emitter3880* emitter = fn_800339F0(NULL, 0x1D);
    Particle3880* p;

    if (emitter != NULL) {
        p = emitter->particles;
        do {
            p->_4A = 0;
            p->_48 = 0;
            p->_4C = 0;
            p = p->next;
        } while (p != NULL);
    }
    pitchingMachinePitching(0x1D);
}

// .text:0x00150010 size:0x60 mapped:0x8078F0A4
void fn_3_150010(s8 index) {
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES ||
        g_Minigame.GameMode_MiniGame != MINI_GAME_ID_STAR_DASH || index > 4 || index < 0) {
        return;
    }
    fn_3_14F930(index);
}

// .text:0x0014F930 size:0x6E0 mapped:0x8078E9C4
void fn_3_14F930(s8 index) {
    Emitter3880* emitter = fn_800339F0(NULL, 0x1E);

    if (emitter != NULL) {
        fn_3_14F5A4(emitter, index);
    } else {
        emitter = fn_80033A24(fn_3_14ED24, 0x80, 0, lbl_3_data_26C94[1], 1, 0x1E);
        if (emitter != NULL) {
            fn_3_14F8D0(emitter);
            fn_3_14F5A4(emitter, index);
        }
    }
}

// .text:0x0014F8D0 size:0x60 mapped:0x8078E964
void fn_3_14F8D0(Emitter3880* emitter) {
    Particle3880* p;
    u32 i;

    emitter->_10 = lbl_3_common_bss_32724._6C;
    i = 0;
    p = emitter->particles;
    do {
        p->_4F = 0;
        p->_4D = lbl_3_data_26C94[0];
        p->_4E = 0;
        p->_4C = i++ / 18 + 1;
        p = p->next;
    } while (p != NULL);
}

// .text:0x0014F5A4 size:0x32C mapped:0x8078E638
void fn_3_14F5A4(Emitter3880* emitter, s8 index) {
    Particle3880* p;
    u32 i;

    i = 0;
    p = emitter->particles;
    do {
        if (p->_4C == index + 1) {
            p->_4A = lbl_3_data_26C94[7];
            p->color[3] = lbl_3_data_26C94[5];
            p->_38 = p->_3C = lbl_3_data_26C94[2] / 100000.0f;
            p->_48 = p->_4A / 18.0f * i;
            if (p->_48 == 0) {
                fn_3_14EAF4(p);
            }
            p->color[0] = p->color[1] = p->color[2] = 0xFF;
            i++;
            p->_34 = 0.0f;
        }
        p = p->next;
    } while (p != NULL);
}

// .text:0x0014F544 size:0x60 mapped:0x8078E5D8
void fn_3_14F544(Particle3880* p) {
    p->_4A = lbl_3_data_26C94[7];
    p->color[3] = lbl_3_data_26C94[5];
    p->_38 = p->_3C = lbl_3_data_26C94[2] / 100000.0f;
}

// .text:0x0014F3CC size:0x178 mapped:0x8078E460
void fn_3_14F3CC(Particle3880* p) {
    Vec offset = { 0.0f, 0.0f, 0.0f };
    f32 drop = p->_4C < 5 ? 1.25f : 0.5f;
    s16 spreadX = p->_4C < 5 ? 20000 : 10000;
    s16 spreadY = p->_4C < 5 ? 20000 : 10000;

    offset.x += (rand() % spreadX - spreadX / 2) / 10000.0f;
    offset.y += (rand() % spreadY - spreadY / 2) / 10000.0f;
    p->pos.x = offset.x;
    p->pos.y = offset.y - drop;
    p->pos.z = offset.z;
}

// .text:0x0014ED24 size:0x6A8 mapped:0x8078DDB8
BOOL fn_3_14ED24(Emitter3880* emitter) {
    return 0;
}

// .text:0x0014EAF4 size:0x230 mapped:0x8078DB88
void fn_3_14EAF4(Particle3880* p) {
    Vec offset = { 0.0f, 0.0f, 0.0f };

    if (p->_4C == 5) {
        offset.x += (rand() % 10000 - 5000) / 10000.0f;
        offset.y += (rand() % 10000 - 5000) / 10000.0f;
        p->pos.x = offset.x;
        p->pos.y = offset.y - 0.5f;
        p->pos.z = offset.z;
    } else {
        p->pos.x = p->pos.y = p->pos.z = 0.0f;
    }
    fn_3_14E9F0(p);
}

// .text:0x0014E9F0 size:0x104 mapped:0x8078DA84
void fn_3_14E9F0(Particle3880* p) {
    Vec offset;
    u8 kind;

    if (p->_4C < 5) {
        kind = lbl_3_data_26CB8[(u32)rand() % 23];
        offset.x = offset.y = offset.z = 0.0f;
        if (!fn_8001B728(p->_4C - 1, kind, &offset)) {
            memset(&offset, 0, sizeof(Vec));
            fn_8001B728(p->_4C - 1, 4, &offset);
        }
    } else {
        offset.x = g_Minigame._6E8;
        offset.y = -g_Minigame._6EC;
        offset.z = g_Minigame._6F0;
    }
    p->pos.x += offset.x;
    p->pos.y += offset.y;
    p->pos.z += offset.z;
}

// .text:0x0014E988 size:0x68 mapped:0x8078DA1C
void fn_3_14E988(s8 index) {
    Emitter3880* emitter = fn_800339F0(NULL, 0x1E);
    Particle3880* p;

    if (emitter != NULL) {
        p = emitter->particles;
        do {
            if (p->_4C == index + 1) {
                p->_4A = 0;
            }
            p = p->next;
        } while (p != NULL);
    }
}

// .text:0x0014E920 size:0x68 mapped:0x8078D9B4
void fn_3_14E920(s8 index) {
    Emitter3880* emitter = fn_800339F0(NULL, 0x1E);
    Particle3880* p;

    if (emitter != NULL) {
        p = emitter->particles;
        do {
            if (p->_4C == index + 1) {
                p->_4A = 0;
            }
            p = p->next;
        } while (p != NULL);
    }
}

// .text:0x0014E894 size:0x8C mapped:0x8078D928
void fn_3_14E894(void) {
    u32 i;

    for (i = 0; i < 4; i++) {
        s8 idx = i;
        fn_3_14E988(idx);
    }
    pitchingMachinePitching(0x1E);
}

// .text:0x0014E810 size:0x84 mapped:0x8078D8A4
void fn_3_14E810(void) {
    u32 i;

    for (i = 0; i < 4; i++) {
        fn_3_14E920(i);
    }
    pitchingMachinePitching(0x1E);
}

// .text:0x0014E7C0 size:0x50 mapped:0x8078D854
void fn_3_14E7C0(Vec* pos) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES &&
        g_Minigame.GameMode_MiniGame == MINI_GAME_ID_STAR_DASH && pos != NULL) {
        fn_3_14E234(pos);
    }
}

// .text:0x0014E234 size:0x58C mapped:0x8078D2C8
void fn_3_14E234(Vec* pos) {
    EmitterSlot3880 tmp;
    Emitter3880* emitter;
    Emitter3880* added;
    Particle3880* last;

    emitter = fn_800339F0(NULL, 0x1F);
    if (emitter != NULL) {
        added = fn_800337CC(&tmp.base, lbl_3_data_26CD0[1], 1);
        if (added == NULL) {
            return;
        }
        fn_3_14DF6C(added, pos);
        for (last = emitter->particles; last->next != NULL; last = last->next) {}
        last->next = added->particles;
        emitter->count += added->count;
    } else {
        emitter = fn_80033A24(fn_3_14DD04, 0x80, 0, lbl_3_data_26CD0[1], 1, 0x1F);
        if (emitter != NULL) {
            fn_3_14DF6C(emitter, pos);
        }
    }
}

// .text:0x0014DF6C size:0x2C8 mapped:0x8078D000
void fn_3_14DF6C(Emitter3880* emitter, Vec* pos) {
    Particle3880* p;

    p = emitter->particles;
    emitter->_10 = lbl_3_common_bss_32724._6C;
    do {
        p->_4D = lbl_3_data_26CD0[0];
        p->_4E = 0;
        p->pos.x = pos->x + (rand() % 1000 - 500) / 1000.0f;
        p->pos.y = -(0.75f + pos->y);
        p->pos.z = pos->z + (rand() % 1000 - 500) / 1000.0f;
        p->vel.x = p->vel.z = 0.0f;
        p->vel.y = lbl_3_data_26CD0[9] / 100000.0f;
        p->vel.y += (rand() % (s32)(1000.0f * (p->vel.y / 2)) - 1000.0f * (p->vel.y / 4)) / 1000.0f;
        p->color[0] = p->color[1] = p->color[2] = 0xFF;
        p->color[3] = lbl_3_data_26CD0[6];
        p->_1C.x = (rand() % 1000 + 500) / 1000.0f;
        p->_38 = p->_3C = lbl_3_data_26CD0[3] / 100000.0f * p->_1C.x;
        p->_4A = lbl_3_data_26CD0[2];
        p->_48 = 0;
        p = p->next;
    } while (p != NULL);
}

// .text:0x0014DD04 size:0x268 mapped:0x8078CD98
BOOL fn_3_14DD04(Emitter3880* emitter) {
    Particle3880* p;
    Particle3880** link;
    Particle3880* last;
    s32 alive = 0;
    s32 alpha;
    s32 step;
    f32 grow;

    p = emitter->particles = fn_80031F34(emitter->particles, emitter->count);
    link = &emitter->particles;
    last = NULL;
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_DSTALPHA, GX_LO_CLEAR);
    do {
        if (p->_4A != 0) {
            fn_8003403C(p->_38, p->_3C);
            fn_80033CC8(p, emitter->_10);
            p->pos.y -= p->vel.y;
            p->vel.y -= lbl_3_data_26CD0[10] / 100000.0f;
            alpha = p->color[3];
            if (lbl_3_data_26CD0[2] / p->_4A < 2) {
                grow = p->_1C.x * ((lbl_3_data_26CD0[4] - lbl_3_data_26CD0[3]) / 100000.0f / (lbl_3_data_26CD0[2] / 2));
                step = (lbl_3_data_26CD0[7] - lbl_3_data_26CD0[6]) / (lbl_3_data_26CD0[2] / 2);
            } else {
                grow = p->_1C.x * ((lbl_3_data_26CD0[5] - lbl_3_data_26CD0[4]) / 100000.0f / (lbl_3_data_26CD0[2] / 2));
                step = (lbl_3_data_26CD0[8] - lbl_3_data_26CD0[7]) / (lbl_3_data_26CD0[2] / 2);
            }
            p->_38 += grow;
            p->_3C = p->_38;
            alpha += step;
            if (alpha < 0) {
                alpha = 0;
            } else if (alpha > 255) {
                alpha = 255;
            }
            p->color[3] = alpha;
            p->_4A--;
            if (p->_4A == 0) {
                *link = p->next;
                if (last != NULL) {
                    last->next = p;
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
    return alive == 0;
}

// .text:0x0014DCE0 size:0x24 mapped:0x8078CD74
void fn_3_14DCE0(void) {
    pitchingMachinePitching(0x1F);
}

// .text:0x0014DC80 size:0x60 mapped:0x8078CD14
void fn_3_14DC80(s8 barrel) {
    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES ||
        g_Minigame.GameMode_MiniGame != MINI_GAME_ID_BARREL_BATTER || barrel >= 15 || barrel < 0) {
        return;
    }
    fn_3_14D710(barrel);
}

// .text:0x0014D710 size:0x570 mapped:0x8078C7A4
// The second inlined fn_3_14D44C swaps its particle and count registers (98.81%);
// the first copy matches.
void fn_3_14D710(s8 barrel) {
    Emitter3880* emitter = fn_800339F0(NULL, 0x20);

    if (emitter != NULL) {
        fn_3_14D44C(emitter, barrel);
    } else {
        emitter = fn_80033A24(fn_3_14CECC, 0xF0, 0, lbl_3_data_26D00[2], 1, 0x20);
        if (emitter != NULL) {
            fn_3_14D6D4(emitter);
            fn_3_14D44C(emitter, barrel);
        }
    }
}

// .text:0x0014D6D4 size:0x3C mapped:0x8078C768
void fn_3_14D6D4(Emitter3880* emitter) {
    Particle3880* p;

    emitter->_10 = lbl_3_common_bss_32724._6C;
    p = emitter->particles;
    do {
        p->_46 = 0;
        p->_45 = 0;
        p->_44 = 0;
        p->_4A = 0;
        p->_4E = 0;
        p = p->next;
    } while (p != NULL);
}

// .text:0x0014D44C size:0x288 mapped:0x8078C4E0
void fn_3_14D44C(Emitter3880* emitter, s32 barrel) {
    u8 index = barrel;
    Particle3880* p;
    s32 n;

    n = 0;
    p = emitter->particles;
    do {
        if (p->_44 == 0 && p->_4A == 0) {
            if (n < 3) {
                p->_44 = 1;
                p->_45 = index;
                p->_46 = 0xFF;
                p->_4D = lbl_3_data_26D00[0];
                p->_38 = p->_3C = lbl_3_data_26D00[4];
                p->color[3] = lbl_3_data_26D00[7];
                fn_3_14D318(p);
                p->_4A = lbl_3_data_26D00[17];
                p->_48 = 0;
            } else {
                p->_44 = 2;
                p->_45 = index;
                p->_46 = (n - 3) / 5;
                p->_4D = lbl_3_data_26D00[1];
                p->_38 = p->_3C = lbl_3_data_26D00[11];
                p->color[3] = lbl_3_data_26D00[14];
                p->_48 = ((n - 3) % 5) * 4 + 1;
                p->_4A = lbl_3_data_26D00[18];
            }
            p->color[0] = p->color[1] = p->color[2] = 0xFF;
            n++;
        }
        p = p->next;
    } while (p != NULL && n < 43);
}

// .text:0x0014D318 size:0x134 mapped:0x8078C3AC
void fn_3_14D318(Particle3880* p) {
    VecXYZ* barrel = &g_Minigame.barrels[p->_45].currentPos;

    p->pos.x = barrel->x;
    p->pos.y = -(barrel->y + lbl_3_data_21770[3] / 2);
    p->pos.z = barrel->z;
    p->pos.x += (rand() % 100 - 50) / 100.0;
    p->pos.y += (rand() % 100 - 50) / 100.0;
}

// .text:0x0014D2C0 size:0x58 mapped:0x8078C354
void fn_3_14D2C0(Particle3880* p) {
    UnkActor3880* actor = &lbl_8036E548._0068[p->_45 + 16];
    UnkModel3880* model = actor->_34->_18[p->_46];

    p->pos.x = (*model->_EC)[0][3];
    p->pos.y = (*model->_EC)[1][3];
    p->pos.z = (*model->_EC)[2][3];
}

// .text:0x0014CECC size:0x3F4 mapped:0x8078BF60
BOOL fn_3_14CECC(Emitter3880* emitter) {
    Particle3880* p;

    if (lbl_80366158._28 != 0) {
        return FALSE;
    }
    fn_80033620(emitter);
    p = emitter->particles;
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    do {
        if (p->_44 != 0 && p->_4A != 0) {
            if (p->_48 <= 0) {
                if (p->_44 == 1) {
                    fn_3_14CD40(emitter, p);
                } else {
                    if (p->_48 == 0) {
                        fn_3_14D2C0(p);
                    }
                    fn_3_14CBB4(emitter, p);
                }
                p->_4A--;
                if (p->_4A == 0) {
                    fn_3_14CA98(p);
                }
            }
            p->_48--;
        }
        p = p->next;
    } while (p != NULL);
    return FALSE;
}

// .text:0x0014CD40 size:0x18C mapped:0x8078BDD4
void fn_3_14CD40(Emitter3880* emitter, Particle3880* p) {
    s32 alpha;
    s32 step;
    f32 grow;

    GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_CLEAR);
    fn_8003403C(p->_38, p->_3C);
    fn_80033CC8(p, emitter->_10);
    alpha = p->color[3];
    if (-p->_48 < lbl_3_data_26D00[3]) {
        grow = lbl_3_data_26D00[5] / 100000.0f / lbl_3_data_26D00[3];
        step = lbl_3_data_26D00[8] / lbl_3_data_26D00[3];
    } else {
        grow = (lbl_3_data_26D00[6] - lbl_3_data_26D00[5]) / 100000.0f / (lbl_3_data_26D00[17] - lbl_3_data_26D00[3]);
        step = (lbl_3_data_26D00[9] - lbl_3_data_26D00[8]) / (lbl_3_data_26D00[17] - lbl_3_data_26D00[3]);
    }
    alpha += step;
    if (alpha > 255) {
        alpha = 255;
    } else if (alpha < 0) {
        alpha = 0;
    }
    p->color[3] = alpha;
    p->color[0] = p->color[1] = p->color[2] = p->color[3];
    p->_38 += grow;
    p->_3C = p->_38;
}

// .text:0x0014CBB4 size:0x18C mapped:0x8078BC48
void fn_3_14CBB4(Emitter3880* emitter, Particle3880* p) {
    s32 alpha;
    s32 step;
    f32 grow;

    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    fn_8003403C(p->_38, p->_3C);
    fn_80033CC8(p, emitter->_10);
    alpha = p->color[3];
    if (-p->_48 < lbl_3_data_26D00[10]) {
        grow = lbl_3_data_26D00[12] / 100000.0f / lbl_3_data_26D00[10];
        step = lbl_3_data_26D00[15] / lbl_3_data_26D00[10];
    } else {
        grow = (lbl_3_data_26D00[13] - lbl_3_data_26D00[12]) / 100000.0f / (lbl_3_data_26D00[18] - lbl_3_data_26D00[10]);
        step = (lbl_3_data_26D00[16] - lbl_3_data_26D00[15]) / (lbl_3_data_26D00[18] - lbl_3_data_26D00[10]);
    }
    alpha += step;
    if (alpha > 255) {
        alpha = 255;
    } else if (alpha < 0) {
        alpha = 0;
    }
    p->color[3] = alpha;
    p->color[0] = p->color[1] = p->color[2] = p->color[3];
    p->_38 += grow;
    p->_3C = p->_38;
}

// .text:0x0014CB28 size:0x8C mapped:0x8078BBBC
void fn_3_14CB28(s8 index) {
    if (index >= 15 || index < 0) {
        return;
    }
    fn_3_14CAB4(index);
}

// .text:0x0014CAB4 size:0x74 mapped:0x8078BB48
void fn_3_14CAB4(s8 index) {
    Emitter3880* emitter = fn_800339F0(NULL, 0x20);
    Particle3880* p;

    if (emitter != NULL) {
        p = emitter->particles;
        do {
            if (p->_45 == index) {
                fn_3_14CA98(p);
            }
            p = p->next;
        } while (p != NULL);
    }
}

// .text:0x0014CA98 size:0x1C mapped:0x8078BB2C
void fn_3_14CA98(Particle3880* p) {
    p->_44 = 0;
    p->_45 = 0xFF;
    p->_4A = 0;
    p->_4C = 0;
}

// .text:0x0014CA00 size:0x98 mapped:0x8078BA94
void fn_3_14CA00(void) {
    u32 i;

    for (i = 0; i < 15; i++) {
        fn_3_14CAB4(i);
    }
    pitchingMachinePitching(0x20);
}

// .text:0x0014C904 size:0xFC mapped:0x8078B998
void fn_3_14C904(void) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES &&
        g_Minigame.GameMode_MiniGame == MINI_GAME_ID_CHAINCHOMP_SPRINT) {
        fn_3_14C830();
    }
}

// .text:0x0014C830 size:0xD4 mapped:0x8078B8C4
void fn_3_14C830(void) {
    Emitter3880* emitter = fn_80033A24(fn_3_14C4C8, 0x80, 0, lbl_3_data_26D5C[1], 1, 0xA);

    if (emitter != NULL) {
        fn_3_14C79C(emitter);
    }
}

// .text:0x0014C79C size:0x94 mapped:0x8078B830
void fn_3_14C79C(Emitter3880* emitter) {
    Particle3880* p;

    emitter->_10 = lbl_3_common_bss_32724._6C;
    p = emitter->particles;
    p->_4D = lbl_3_data_26D5C[0];
    p->_4E = 0;
    p->_4A = lbl_3_data_26D5C[2];
    p->_38 = p->_3C = lbl_3_data_26D5C[4] / 100000.0f;
    p->color[3] = lbl_3_data_26D5C[7];
    p->color[0] = p->color[1] = p->color[2] = 0xFF;
}

// .text:0x0014C4C8 size:0x2D4 mapped:0x8078B55C
BOOL fn_3_14C4C8(Emitter3880* emitter) {
    Particle3880* p;
    s32 alpha;
    s32 step;
    f32 grow;

    if (lbl_80366158._28 != 0) {
        return FALSE;
    }
    p = emitter->particles;
    if (p->_4A != 0) {
        GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_ONE, GX_BL_ONE, GX_LO_CLEAR);
        fn_3_14C3BC(p);
        fn_8003403C(p->_38, p->_3C);
        fn_80033CC8(p, emitter->_10);
        alpha = p->color[3];
        if (lbl_3_data_26D5C[2] - lbl_3_data_26D5C[3] < p->_4A) {
            grow = (lbl_3_data_26D5C[5] - lbl_3_data_26D5C[4]) / 100000.0f / lbl_3_data_26D5C[3];
            step = (lbl_3_data_26D5C[8] - lbl_3_data_26D5C[7]) / lbl_3_data_26D5C[3];
        } else {
            grow = (lbl_3_data_26D5C[6] - lbl_3_data_26D5C[5]) / 100000.0f / (lbl_3_data_26D5C[2] - lbl_3_data_26D5C[3]);
            step = (lbl_3_data_26D5C[9] - lbl_3_data_26D5C[8]) / (lbl_3_data_26D5C[2] - lbl_3_data_26D5C[3]);
        }
        alpha += step;
        if (alpha < 0) {
            alpha = 0;
        }
        if (alpha > 255) {
            alpha = 255;
        }
        p->_38 += grow;
        p->_3C = p->_38;
        p->color[3] = alpha;
        p->color[0] = p->color[1] = p->color[2] = p->color[3];
        p->_4A--;
    } else {
        return TRUE;
    }
    return FALSE;
}

// .text:0x0014C3BC size:0x10C mapped:0x8078B450
void fn_3_14C3BC(Particle3880* p) {
    Vec offset;
    Mtx rot;

    PSVECScale(&lbl_3_data_26D50, 0.75f, &offset);
    PSMTXRotRad(rot, 'Y', shortAngleToRad(g_Minigame._1AF8));
    PSMTXMultVec(rot, &offset, &offset);
    p->pos.x = g_Minigame._1AE0 + offset.x + lbl_3_data_26D5C[5] / 100000.0f / 2.0f;
    p->pos.y = offset.y - (g_Minigame._1AE4 + lbl_3_data_26D5C[5] / 100000.0f / 2.0f);
    p->pos.z = g_Minigame._1AE8 + offset.z;
}

// .text:0x0014C398 size:0x24 mapped:0x8078B42C
void fn_3_14C398(void) {
    pitchingMachinePitching(0x21);
}

// .text:0x0014C348 size:0x50 mapped:0x8078B3DC
void fn_3_14C348(void) {
    return;
}

// .text:0x0014BECC size:0x47C mapped:0x8078AF60
void fn_3_14BECC(void) {
    return;
}

// .text:0x0014BCB0 size:0x21C mapped:0x8078AD44
// Volatile int and float registers of the spread math differ (99.26%): the target loads the
// 2.0f factor late, as here, but multiplies it first.
void fn_3_14BCB0(Emitter3880* emitter, Vec* pos, u8 big) {
    Particle3880* p;
    s32* cfg;
    u32 count;
    f32 angle;
    f32 spread;
    f32 deg;
    s32 r;
    f32 radius = 2.0f;

    emitter->_10 = lbl_3_common_bss_32724._6C;
    count = 0;
    p = emitter->particles;
    cfg = big ? lbl_3_data_26DC4 : lbl_3_data_26D88;
    do {
        if (p->_4A == 0) {
            p->_4D = cfg[0];
            p->_4E = 0;
            p->_4A = cfg[2];
            p->_38 = p->_3C = cfg[4] / 100000.0f;
            p->color[3] = cfg[10];
            p->color[0] = cfg[7];
            p->color[1] = cfg[8];
            p->color[2] = cfg[9];
            r = rand();
            deg = 180.0 / cfg[1] * count;
            spread = (2.0 * (r / 32767.0f - 0.5)) * radius;
            angle = 0.017453292f * deg;
            p->pos.x = pos->x + spread * cosf_kludge(angle);
            p->pos.y = pos->y - spread * sinf_kludge(angle) - 1.0;
            p->pos.z = pos->z;
            p->_4F = big;
            count++;
        }
        p = p->next;
    } while (p != NULL && count < lbl_3_data_26D88[1]);
}

// .text:0x0014BA40 size:0x270 mapped:0x8078AAD4
BOOL fn_3_14BA40(Emitter3880* emitter) {
    Particle3880* p;
    Particle3880** link;
    Particle3880* removed;
    Particle3880* last;
    s32* cfg;
    s32 total;
    s32 fade;
    s32 alive = 0;
    s32 alpha;
    s32 step;
    f32 grow;

    if (lbl_80366158._28 != 0) {
        return FALSE;
    }
    p = emitter->particles = fn_80031F34(emitter->particles, emitter->count);
    link = &emitter->particles;
    last = NULL;
    removed = NULL;
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    do {
        if (p->_4A != 0) {
            cfg = !p->_4F ? lbl_3_data_26D88 : lbl_3_data_26DC4;
            total = cfg[2];
            fade = cfg[3];
            fn_8003403C(p->_38, p->_3C);
            fn_80033CC8(p, emitter->_10);
            alpha = p->color[3];
            if (total - p->_4A < fade) {
                grow = (cfg[5] - cfg[4]) / fade / 100000.0f;
                step = (cfg[11] - cfg[10]) / fade;
            } else {
                grow = (cfg[6] - cfg[5]) / (total - fade) / 100000.0f;
                step = (cfg[12] - cfg[11]) / (total - fade);
            }
            alpha += step;
            if (alpha > 255) {
                alpha = 255;
            }
            if (alpha < 0) {
                alpha = 0;
            }
            p->color[3] = alpha;
            p->_38 += grow;
            p->_3C = p->_38;
            p->_4A--;
            if (p->_4A == 0) {
                *link = p->next;
                if (last != NULL) {
                    last->next = p;
                } else {
                    removed = p;
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
    if (removed != NULL) {
        p = removed;
        do {
            p->_4C = 0;
            p->_48 = 0;
        } while ((p = p->next) != NULL);
        fn_80033794(removed);
    }
    return alive == 0;
}

// .text:0x0014B9F0 size:0x50 mapped:0x8078AA84
void fn_3_14B9F0(void) {
    Emitter3880* emitter = fn_800339F0(NULL, 0x22);
    Particle3880* p;

    if (emitter != NULL) {
        p = emitter->particles;
        do {
            p->_4A = 0;
            p = p->next;
        } while (p != NULL);
    }
    pitchingMachinePitching(0x22);
}

// .text:0x0014B9A0 size:0x50 mapped:0x8078AA34
void fn_3_14B9A0(u32 duration, Vec* pos) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES &&
        g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER && pos != NULL) {
        fn_3_14B92C(duration, pos);
    }
}

// .text:0x0014B92C size:0x74 mapped:0x8078A9C0
void fn_3_14B92C(u32 duration, Vec* pos) {
    Emitter3880* emitter = fn_80033A24(fn_3_14AC40, 0x80, 0, lbl_3_data_26E24[2], 1, 0x23);

    if (emitter != NULL) {
        fn_3_14B53C((PathEmitter3880*)emitter, duration, pos);
    }
}

// .text:0x0014B53C size:0x3F0 mapped:0x8078A5D0
// 99.90%: the inlined fn_3_14B248 keeps the angle in f28 and its cosine in f29 in the
// target, the reverse here; fn_3_14B248 itself matches.
void fn_3_14B53C(PathEmitter3880* emitter, u32 duration, Vec* pos) {
    Vec diff;
    f32 dist;
    f32 dist2;
    Particle3880* p;
    s32 i = 0;

    emitter->_18 = *pos;
    emitter->base._10 = lbl_3_common_bss_32724._6C;
    emitter->_34 = duration;
    emitter->_36 = duration;
    PSVECSubtract(&lbl_3_data_26E00[0], &lbl_3_data_26E00[1], &diff);
    dist = PSVECMag(&diff);
    PSVECSubtract(&lbl_3_data_26E00[1], &lbl_3_data_26E00[2], &diff);
    dist2 = PSVECMag(&diff);
    emitter->_30 = dist / ((dist2 + dist) / duration);
    fn_3_14B3F4(emitter);
    p = emitter->base.particles;
    do {
        p->_4D = lbl_3_data_26E24[0];
        p->_4E = 0;
        p->_48 = i * (emitter->_34 / (f32)lbl_3_data_26E24[2]);
        p->color[0] = p->color[1] = p->color[2] = 0xFF;
        p->_4A = lbl_3_data_26E24[1];
        if (p->_48 == 0) {
            fn_3_14B248(emitter, p);
        }
        p = p->next;
        i++;
    } while (p != NULL);
}

// .text:0x0014B3F4 size:0x148 mapped:0x8078A488
void fn_3_14B3F4(PathEmitter3880* emitter) {
    Vec* from;
    Vec* to;
    f32 t;
    f32 height;

    if ((f32)(emitter->_34 - emitter->_36) < emitter->_30) {
        from = &lbl_3_data_26E00[0];
        to = &lbl_3_data_26E00[1];
        t = (emitter->_34 - emitter->_36) / emitter->_30;
    } else {
        from = &lbl_3_data_26E00[1];
        to = &lbl_3_data_26E00[2];
        t = (emitter->_34 - emitter->_36) / (emitter->_34 - emitter->_30);
    }
    height = fn_3_119D28();
    emitter->_24.x = emitter->_18.x + height * (from->x * (1.0f - t) + to->x * t);
    emitter->_24.y = emitter->_18.y + height * (from->y * (1.0f - t) + to->y * t);
    emitter->_24.z = emitter->_18.z + height * (from->z * (1.0f - t) + to->z * t);
}

// .text:0x0014B248 size:0x1AC mapped:0x8078A2DC
void fn_3_14B248(PathEmitter3880* emitter, Particle3880* p) {
    f32 angle;
    f32 dist;
    Vec offset;

    p->_38 = p->_3C = lbl_3_data_26E24[3] / 100000.0f;
    p->color[3] = lbl_3_data_26E24[5];
    angle = 0.017453292f * (rand() % 360);
    dist = (rand() % 200u) / 1000.0;
    offset.x = dist * cosf_kludge(angle);
    offset.y = dist * sinf_kludge(angle);
    offset.z = 0.0f;
    p->pos.x = emitter->_24.x + offset.x;
    p->pos.y = emitter->_24.y + offset.y;
    p->pos.z = emitter->_24.z + offset.z;
    p->_4A = lbl_3_data_26E24[1];
}

// .text:0x0014AC40 size:0x608 mapped:0x80789CD4
BOOL fn_3_14AC40(Emitter3880* emitter) {
    return 0;
}

// .text:0x0014AC1C size:0x24 mapped:0x80789CB0
void fn_3_14AC1C(void) {
    pitchingMachinePitching(0x23);
}

// .text:0x0014A90C size:0x310 mapped:0x807899A0
void fn_3_14A90C(Vec* pos) {
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES &&
        g_Minigame.GameMode_MiniGame == MINI_GAME_ID_BARREL_BATTER && pos != NULL) {
        fn_3_14A62C(pos);
    }
}

// .text:0x0014A62C size:0x2E0 mapped:0x807896C0
void fn_3_14A62C(Vec* pos) {
    Emitter3880* emitter = fn_80033A24(fn_3_14A188, 0x80, 0, lbl_3_data_26E40[1], 1, 0x24);

    if (emitter != NULL) {
        fn_3_14A37C(emitter, pos);
    }
}

// .text:0x0014A37C size:0x2B0 mapped:0x80789410
void fn_3_14A37C(Emitter3880* emitter, Vec* pos) {
    Particle3880* p;
    u32 i;
    f32 angle;

    emitter->_10 = lbl_3_common_bss_32724._6C;
    p = emitter->particles;
    i = 0;
    do {
        p->_4D = lbl_3_data_26E40[0];
        p->_4E = 0;
        p->_4A = lbl_3_data_26E40[2];
        p->_48 = 0;
        p->pos.x = pos->x;
        p->pos.y = -pos->y;
        p->pos.z = pos->z;
        angle = 360 / lbl_3_data_26E40[1] * i;
        angle = 0.017453292f * angle;
        p->pos.x += lbl_3_data_26E40[3] * cosf_kludge(angle) / 100000.0f;
        p->pos.y += lbl_3_data_26E40[3] * sinf_kludge(angle) / 100000.0f;
        p->_38 = p->_3C = lbl_3_data_26E40[5] / 100000.0f;
        p->color[0] = p->color[1] = p->color[2] = 0xFF;
        p->color[3] = lbl_3_data_26E40[9];
        p->vel.x = 0.0f;
        p->vel.y = lbl_3_data_26E40[12] - rand() % lbl_3_data_26E40[13];
        p->vel.y /= 100000.0f;
        p->vel.y *= (rand() % 2) * -2 + 1;
        p->vel.z = lbl_3_data_26E40[6] - rand() % lbl_3_data_26E40[7];
        p->vel.z /= 100000.0f;
        i++;
        p = p->next;
    } while (p != NULL);
}

// .text:0x0014A188 size:0x1F4 mapped:0x8078921C
BOOL fn_3_14A188(Emitter3880* emitter) {
    Particle3880* p;
    s32 alpha;
    s32 alive = 0;
    s32 step;
    f32 grow;

    if (lbl_80366158._28 != 0) {
        return FALSE;
    }
    fn_80033620(emitter);
    p = emitter->particles;
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    do {
        if (p->_4A != 0) {
            alpha = p->color[3];
            fn_80033F64(p->_38, p->_3C, p->vel.x);
            fn_80033CC8(p, emitter->_10);
            if (lbl_3_data_26E40[2] - p->_4A < lbl_3_data_26E40[4]) {
                grow = (p->vel.z - lbl_3_data_26E40[5] / 100000.0f) / lbl_3_data_26E40[4];
                step = (lbl_3_data_26E40[10] - lbl_3_data_26E40[9]) / lbl_3_data_26E40[4];
            } else {
                grow = (lbl_3_data_26E40[8] / 100000.0f + p->vel.z) / (lbl_3_data_26E40[2] - lbl_3_data_26E40[4]);
                step = (lbl_3_data_26E40[11] - lbl_3_data_26E40[10]) / (lbl_3_data_26E40[2] - lbl_3_data_26E40[4]);
            }
            alpha += step;
            if (alpha < 0) {
                alpha = 0;
            }
            if (alpha > 255) {
                alpha = 255;
            }
            p->color[3] = alpha;
            p->_38 += grow;
            p->_3C = p->_38;
            p->vel.x += p->vel.y;
            if (--p->_4A != 0) {
                alive++;
            }
        }
        p = p->next;
    } while (p != NULL);
    return alive == 0;
}

// .text:0x0014A164 size:0x24 mapped:0x807891F8
void fn_3_14A164(void) {
    pitchingMachinePitching(0x24);
}

// .text:0x0014A070 size:0xF4 mapped:0x80789104
void fn_3_14A070(s32* values, s32 count) {
    u32 i;

    lbl_3_bss_B85C[0] = -1;
    lbl_3_bss_B85C[1] = -1;
    lbl_3_bss_B85C[2] = -1;
    lbl_3_bss_B85C[3] = -1;
    if (count > 4 || count == 0 || values == NULL) {
        return;
    }
    for (i = 0; i < count; i++) {
        lbl_3_bss_B85C[i] = values[i];
    }
}

// .text:0x00149BA8 size:0x4C8 mapped:0x80788C3C
void fn_3_149BA8(void) {
    return;
}

// .text:0x0014975C size:0x44C mapped:0x807887F0
void fn_3_14975C(void) {
    return;
}

// .text:0x00149340 size:0x41C mapped:0x807883D4
void fn_3_149340(void) {
    return;
}

// .text:0x00148FD0 size:0x370 mapped:0x80788064
// 90.13%: the target loads lbl_3_data_26E7C[6] and the player pointer before the float
// setup and schedules the angle math differently.
void fn_3_148FD0(PlayerEmitter3880* emitter, Particle3880* p) {
    UnkPlayer3880* player = lbl_8036E548._2C50[emitter->player];
    u8 base = lbl_3_data_26E7C[6];
    u8 span;
    f32 angle;
    f32 s;
    f32 c;
    s32 range;

    p->pos.x = 0.0f;
    p->pos.y = -(lbl_3_data_26E7C[5] / 100000.0f + player->_34.y);
    p->pos.z = 0.0f;
    angle = 0.017453292f * (15.0f * ((lbl_3_data_26E7C[0] / 2 - p->_4A) / (lbl_3_data_26E7C[0] / 2.0f)));
    s = sinf_kludge(angle);
    c = cosf_kludge(angle);
    p->vel.x = s * lbl_3_data_26E7C[1] / 100000.0f;
    p->vel.y = c * lbl_3_data_26E7C[1] / 100000.0f;
    p->vel.z = 0.0f;
    p->_1C.x = p->_1C.y = p->_1C.z = 0.0f;
    range = 1000.0f * (lbl_3_data_26E7C[2] / 100000.0f);
    p->_28 = (rand() % range) / 1000.0f;
    p->_2C = (rand() % range) / 1000.0f;
    p->_30 = (rand() % range) / 1000.0f;
    p->color[3] = p->_47 = 0xFF;
    span = 0xFF - lbl_3_data_26E7C[6];
    p->color[1] = base + rand() % span;
    p->color[2] = base + rand() % span;
    p->_44 = base + rand() % span;
    p->_45 = base + rand() % span;
    p->_46 = base + rand() % span;
    p->_4C = 0;
}

// .text:0x00148EF0 size:0xE0 mapped:0x80787F84
void fn_3_148EF0(Particle3880* p, f32 angle) {
    f32 rad = 0.017453292f * angle;
    f32 s = sinf_kludge(rad);
    f32 c = cosf_kludge(rad);

    p->vel.x = s * lbl_3_data_26E7C[1] / 100000.0f;
    p->vel.y = c * lbl_3_data_26E7C[1] / 100000.0f;
    p->vel.z = 0.0f;
}

// .text:0x0014841C size:0xAD4 mapped:0x807874B0
void fn_3_14841C(void) {
    return;
}

// .text:0x001483D4 size:0x48 mapped:0x80787468
u8 fn_3_1483D4(void) {
    return rand() % 5 == 0;
}

// .text:0x00148254 size:0x180 mapped:0x807872E8
void fn_3_148254(PlayerEmitter3880* emitter, Particle3880* p) {
    Vec pos;
    Mtx mtx;
    Control control;
    f32 halfW = p->_38 / 2;
    f32 halfH = p->_3C / 2;
    UnkPlayer3880* player = lbl_8036E548._2C50[emitter->player];

    lbl_3_bss_B860[0].x = -halfW;
    lbl_3_bss_B860[0].y = -halfH;
    lbl_3_bss_B860[1].x = halfW;
    lbl_3_bss_B860[1].y = -halfH;
    lbl_3_bss_B860[2].x = halfW;
    lbl_3_bss_B860[2].y = halfH;
    lbl_3_bss_B860[3].x = -halfW;
    lbl_3_bss_B860[3].y = halfH;
    PSMTXInverse(fn_80052768_getCamera(0)->view, mtx);
    mtx[0][1] = mtx[1][0] = mtx[1][2] = mtx[2][1] = 0.0f;
    mtx[1][1] = 1.0f;
    pos.x = p->pos.x;
    pos.y = p->pos.y;
    pos.z = p->pos.z;
    PSMTXMultVecSR(mtx, &pos, &pos);
    control.type = 0;
    CTRLSetRotation(&control, p->_1C.x, p->_1C.y, p->_1C.z);
    CTRLSetTranslation(&control, player->_34.x + pos.x, -player->_34.y + pos.y, player->_34.z + pos.z);
    CTRLBuildMatrix(&control, mtx);
    PSMTXConcat(fn_80052768_getCamera(0)->view, mtx, mtx);
    GXLoadPosMtxImm(mtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
}

// .text:0x001480E0 size:0x174 mapped:0x80787174
void fn_3_1480E0(Particle3880* p) {
    s32 i;

    GXSetCullMode(GX_CULL_BACK);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    for (i = 0; i < 4; i++) {
        GXPosition3f32(lbl_3_bss_B860[i].x, lbl_3_bss_B860[i].y, lbl_3_bss_B860[i].z);
        GXColor1u32(*(u32*)p->color);
    }
    GXSetCullMode(GX_CULL_FRONT);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    for (i = 0; i < 4; i++) {
        GXPosition3f32(lbl_3_bss_B860[i].x, lbl_3_bss_B860[i].y, lbl_3_bss_B860[i].z);
        GXColor1u32(*(u32*)&p->_44);
    }
}

// .text:0x00147F94 size:0x14C mapped:0x80787028
void fn_3_147F94(void) {
    GXSetZMode(GX_TRUE, GX_ALWAYS, GX_TRUE);
    GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_RASC);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_RASA);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
}

// .text:0x00147E20 size:0x174 mapped:0x80786EB4
void fn_3_147E20(void) {
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_VTX, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetCullMode(GX_CULL_NONE);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_RASC, GX_CC_TEXC, GX_CC_ZERO);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_RASA, GX_CA_TEXA, GX_CA_ZERO);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
    GXLoadPosMtxImm(fn_80052768_getCamera(0)->view, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
}

// .text:0x00147DFC size:0x24 mapped:0x80786E90
void fn_3_147DFC(void) {
    pitchingMachinePitching(0x25);
}

// .text:0x00147CFC size:0x100 mapped:0x80786D90
void fn_3_147CFC(void) {
    return;
}

// .text:0x00147C00 size:0xFC mapped:0x80786C94
void fn_3_147C00(void) {
    return;
}

// .text:0x00147778 size:0x488 mapped:0x8078680C
void fn_3_147778(void) {
    return;
}

// .text:0x0014737C size:0x3FC mapped:0x80786410
void fn_3_14737C(void) {
    return;
}
