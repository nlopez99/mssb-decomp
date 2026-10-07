#include "game/rep_3520.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "game/rep_28A8.h"
#include "game/rep_540.h"
#include "game/m_sound.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "Dolphin/rand.h"

// One of four objects at g_Minigame + 0xBB0
typedef struct Unk3520Obj {
    /* 0x00 */ Vec _0;
    /* 0x0C */ Vec _C;
    /* 0x18 */ Vec _18;
    /* 0x24 */ Vec _24;
    /* 0x30 */ f32 _30;
    /* 0x34 */ f32 _34;
    /* 0x38 */ s16 _38;
    /* 0x3A */ s16 _3A;
    /* 0x3C */ u8 _3C;
    /* 0x3D */ u8 _3D;
    /* 0x3E */ u8 _3E;
    /* 0x3F */ u8 _3F;
} Unk3520Obj; // size: 0x40

// A spoke's end points, one per player at g_Minigame._1CE8
typedef struct Unk3520Spoke {
    /* 0x00 */ VecXYZ start;
    /* 0x0C */ VecXYZ end;
} Unk3520Spoke; // size: 0x18

// The pieces along the spokes, at g_Minigame._A8
typedef struct Unk3520Piece {
    /* 0x00 */ Vec pos;
    /* 0x0C */ u8 _0C[0x26 - 0xC];
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
} Unk3520Piece; // size: 0x28

// The bonus box, at g_Minigame._CB0
typedef struct Unk3520Box {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec vel;
    /* 0x18 */ u8 _18[0x1C - 0x18];
    /* 0x1C */ s16 _1C;
    /* 0x1E */ u8 _1E;
} Unk3520Box; // size: 0x20

// This minigame's view of g_Minigame
typedef struct Unk3520Minigame {
    /* 0x0000 */ u8 _0000[0xA8];
    /* 0x00A8 */ Unk3520Piece pieces[40];
    /* 0x06E8 */ u8 _06E8[0xBB0 - 0x6E8];
    /* 0x0BB0 */ Unk3520Obj objs[4];
    /* 0x0CB0 */ Unk3520Box box;
    /* 0x0CD0 */ u8 _0CD0[0x1CE8 - 0xCD0];
    /* 0x1CE8 */ Unk3520Spoke spokes[4];
} Unk3520Minigame;

#define MG (*(Unk3520Minigame*)&g_Minigame)

// Elements of the arrays the qsort comparators below order
typedef struct Unk3520Sort {
    /* 0x00 */ f32 _0;
    /* 0x04 */ s16 _4;
    /* 0x06 */ u8 _6[0x11 - 0x6];
    /* 0x11 */ u8 _11;
} Unk3520Sort;

// One per player, at g_Minigame._1DCC
typedef struct Unk3520Cpu {
    /* 0x0 */ f32 _0;
    /* 0x4 */ s16 _4;
    /* 0x6 */ u8 _6[2];
} Unk3520Cpu; // size: 0x8

typedef struct Unk3520Fielder {
    /* 0x000 */ Vec pos;
    /* 0x00C */ f32 _00C;
    /* 0x010 */ u8 _010[0x30 - 0x10];
    /* 0x030 */ f32 _030;
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ u8 _040[0x15C - 0x40];
    /* 0x15C */ f32 _15C;
    /* 0x160 */ u8 _160[0x16C - 0x160];
    /* 0x16C */ f32 _16C;
    /* 0x170 */ u8 _170[0x1C9 - 0x170];
    /* 0x1C9 */ u8 _1C9;
    /* 0x1CA */ u8 _1CA[0x203 - 0x1CA];
    /* 0x203 */ u8 _203;
    /* 0x204 */ u8 _204;
    /* 0x205 */ u8 _205[0x268 - 0x205];
} Unk3520Fielder; // size: 0x268

extern Unk3520Fielder g_Fielders[9];

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern s32 fn_800247E4(s32, s32, s32, s32);
// rep_3880.h declares fn_3_156548 as void(void); it takes the same arguments as fn_3_15730C
extern void fn_3_156548(u32 index, f32 x, f32 y, f32 z);
extern void fn_3_15730C(u32 index, f32 x, f32 y, f32 z);
extern void fn_3_157570(void);
// rep_AC8.h declares fn_3_25844 as void(void)
extern void fn_3_25844(int, int);
extern void fn_800528B4(void);
extern void fn_800115C8(u8);
extern void fn_80011578(void);
extern void fn_3_5A6D4(u8 status);
extern void fn_3_10F550(u8, s16);
extern void changeScene(u8, s16);

extern u8 lbl_3_data_21278[2];
extern f32 lbl_3_data_47BC[5];
extern Vec lbl_3_data_219AC;
extern f32 lbl_3_data_219B8[19];
extern f32 lbl_3_data_21A14[7];
extern s16 lbl_3_data_21A30[6];
extern s16 lbl_3_data_21A04[8];
extern s16 lbl_3_data_21A3C[2][2];
extern s16 lbl_3_data_21A44;
extern Vec lbl_3_data_21A48;
extern f32 lbl_3_data_21A54[3];
extern struct {
    /* 0x0 */ s16 _0;
    /* 0x2 */ s16 _2;
} lbl_3_data_21A60;
extern f32 lbl_3_data_21A64[9];
extern s16 lbl_3_data_21A90[4][4][2];
extern s16 lbl_3_data_21AD0[4][4];
extern s16 lbl_3_data_21AF0[1];
extern f32 lbl_3_data_21AF4;
extern f32 lbl_3_data_21AF8[6];
extern s16 lbl_3_data_21B10[3];
extern u8 lbl_3_data_21B16;
extern s16 lbl_3_data_21B20[4];
extern s8 lbl_3_data_21B88[4];
extern s16 lbl_3_data_21B8C[4];

s8 lbl_3_data_26580 = -1;

// .bss statics, declared in reverse address order (MWCC lays them out last to first)
static u8 lbl_3_bss_B781[1];
static u8 lbl_3_bss_B780;
static u8 lbl_3_bss_B740[0x40] ATTRIBUTE_ALIGN(32);
static GXTexObj lbl_3_bss_B708;
static s32 lbl_3_bss_B704;
static s16 lbl_3_bss_B702;
static u8 lbl_3_bss_B700;

// Waits a random time from the difficulty's range for the elapsed minutes
static inline void Unk3520Obj_SetDelay(Unk3520Obj* obj, u32 t) {
    s16 lo;
    int r;

    obj->_3D = 0;
    obj->_3A = 0;
    lo = lbl_3_data_21A90[g_Minigame.soloMinigameDifficulty][t][0];
    r = random_fn_3_9EE24((lbl_3_data_21A90[g_Minigame.soloMinigameDifficulty][t][1] - lo) * 60);
    obj->_38 = r + lo * 60;
}

// .text:0x0013C468 size:0x328 mapped:0x8077B4FC
void fn_3_13C468(void) {
    return;
}

// .text:0x0013C464 size:0x4 mapped:0x8077B4F8
void fn_3_13C464(void) {
    return;
}

// .text:0x0013BCB8 size:0x7AC mapped:0x8077AD4C
void fn_3_13BCB8(void) {
    return;
}

// .text:0x0013BBF4 size:0xC4 mapped:0x8077AC88
void fn_3_13BBF4(void) {
    switch (g_GameLogic._125) {
    case 0:
        fn_3_10F550(2, lbl_3_data_21278[0]);
        changeScene(1, 6);
        g_GameLogic.FrameCountOfCurrentAtBat_Copy = 0;
        g_GameLogic._125 = 1;
        break;
    case 1:
        if (g_GameLogic.FrameCountOfCurrentAtBat_Copy > lbl_3_data_21278[0] + lbl_3_data_21278[1]) {
            g_GameLogic._125 = 2;
        }
        break;
    case 2:
        fn_3_5A6D4(GAME_STATUS_DEFAULT);
        break;
    }
}

// .text:0x0013BB30 size:0xC4 mapped:0x8077ABC4
void fn_3_13BB30(void) {
    fn_3_F1DC();
    fn_3_1356F8();
    changeScene(1, 6);
    fn_3_5A6D4(GAME_STATUS_LIVE_BALL);
}

// .text:0x0013B9C4 size:0x16C mapped:0x8077AA58
void fn_3_13B9C4(void) {
    u32 i;

    fn_3_157570();
    fn_3_DE4FC();
    fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    fn_80011578();
    for (i = 0; i < 100; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 0;
    }
    g_Minigame._1D50 = 30;
    g_Minigame._1D6C = 0;
    for (i = 0; i < 4; i++) {
        MG.objs[i]._3D = 0;
    }
    g_Minigame._CCE[0] = 0;
}

// .text:0x0013B284 size:0x740 mapped:0x8077A318
void fn_3_13B284(void) {
    return;
}

// .text:0x0013AFE4 size:0x2A0 mapped:0x8077A078
void fn_3_13AFE4(void) {
    return;
}

// .text:0x0013AE1C size:0x1C8 mapped:0x80779EB0
void fn_3_13AE1C(void) {
    u32 i;

    fn_3_DE4FC();
    if (g_Minigame.soloMinigameDifficulty <= MINIGAME_DIFFICULTY_MULTIPLAYER_CHALLENGE_HARD && g_Minigame.multiPlayerInd == 0) {
        if (g_Minigame.minigameControlStruct._1C[g_Minigame._1908] == 1 &&
            g_Minigame.challenge_minigame_haven_tWonYetIndicator == 0) {
            g_Minigame._1A37 = 1;
        } else {
            g_Minigame._1A37 = 2;
        }
    }
    fn_3_5A6D4(GAME_STATUS_MVP_END_GAME);
    fn_80011578();
    for (i = 0; i < 100; i++) {
        g_Minigame.wallBall_coinsVisibleInd[i] = 0;
    }
    g_Minigame._1D50 = 30;
    g_Minigame._1D6C = 0;
    for (i = 0; i < 4; i++) {
        MG.objs[i]._3D = 0;
    }
    g_Minigame._CCE[0] = 0;
}

// .text:0x0013ADC0 size:0x5C mapped:0x80779E54
void fn_3_13ADC0(Vec* out, Vec* v, Vec* n) {
    f32 d = v->x * n->x + v->y * n->y + v->z * n->z;

    d *= 2.0f;
    out->x = v->x - d * n->x;
    out->y = v->y - d * n->y;
    out->z = v->z - d * n->z;
}

// .text:0x0013ACB4 size:0x10C mapped:0x80779D48
void fn_3_13ACB4(void) {
    return;
}

// .text:0x0013AA78 size:0x23C mapped:0x80779B0C
void fn_3_13AA78(void) {
    return;
}

// .text:0x0013A89C size:0x1DC mapped:0x80779930
void fn_3_13A89C(void) {
    return;
}

// .text:0x0013A724 size:0x178 mapped:0x807797B8
void fn_3_13A724(void) {
    f32 speed;
    Vec d;
    f32 dist;

    g_Minigame._6F4 = g_Minigame._6E8;
    g_Minigame._6F8 = g_Minigame._6EC;
    g_Minigame._6FC = g_Minigame._6F0;
    g_Minigame._728 = RandomInt_Game_Range(lbl_3_data_21A30[3], lbl_3_data_21A30[4]);
    speed = RandomF32_Game_Range(lbl_3_data_21A14[0], lbl_3_data_21A14[1]);
    d.x = lbl_3_data_219AC.x - g_Minigame._6E8;
    d.y = lbl_3_data_219AC.y - g_Minigame._6EC;
    d.z = lbl_3_data_219AC.z - g_Minigame._6F0;
    dist = dolsqrtf2(d.x * d.x + d.z * d.z);
    getComponentsFromSAng(random_fn_3_9EE24(0x1000), &d.x, &d.z);
    g_Minigame._70C = d.x * speed + g_Minigame._6F4;
    g_Minigame._714 = d.z * speed + g_Minigame._6FC;
    g_Minigame._710 = lbl_3_data_21A14[4];
    g_Minigame._700 = 0.5f * (g_Minigame._6F4 + g_Minigame._70C);
    g_Minigame._708 = 0.5f * (g_Minigame._6FC + g_Minigame._714);
    g_Minigame._704 = g_Minigame._6F8 + RandomF32_Game_Range(lbl_3_data_21A14[2], lbl_3_data_21A14[3]);
    g_Minigame._726 = 0;
}

// .text:0x0013A0AC size:0x678 mapped:0x80779140
void fn_3_13A0AC(void) {
    return;
}

// .text:0x0013A048 size:0x64 mapped:0x807790DC
void fn_3_13A048(s32 to, s32 from) {
    s16* points = g_Minigame.miniGameCurrentPoints;

    if (points[from] < lbl_3_data_21A04[7]) {
        points[to] += points[from];
        points[from] = 0;
    } else {
        points[to] += lbl_3_data_21A04[7];
        points[from] -= lbl_3_data_21A04[7];
    }
}

// .text:0x00139F84 size:0xC4 mapped:0x80779018
void fn_3_139F84(void) {
    return;
}

// .text:0x00139CA0 size:0x2E4 mapped:0x80778D34
void fn_3_139CA0(void) {
    return;
}

// .text:0x00139808 size:0x498 mapped:0x8077889C
void fn_3_139808(void) {
    return;
}

// .text:0x0013974C size:0xBC mapped:0x807787E0
void fn_3_13974C(void) {
    u32 i;

    for (i = 0; i < 100; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] == 3) {
            g_Minigame.wallBall_coinsVisibleFrameCounter[i]++;
            PSVECAdd((Vec*)&g_Minigame.wallBall_coinCoordinates[i], (Vec*)&g_Minigame.wallBall_coinVelocity[i],
                     (Vec*)&g_Minigame.wallBall_coinCoordinates[i]);
            g_Minigame.wallBall_coinVelocity[i].y += lbl_3_data_219B8[11];
            if (g_Minigame.wallBall_coinVelocity[i].y < 0.0f) {
                g_Minigame.wallBall_coinsVisibleInd[i] = 0;
                g_Minigame._1D6C--;
            }
        }
    }
}

// .text:0x00139700 size:0x4C mapped:0x80778794
void fn_3_139700(void) {
    if (g_Minigame._B6C._40[0] != 0) {
        if (g_Minigame.turnOverStatus != 0) {
            g_Minigame._B6C._40[0] = 0;
        } else {
            fn_3_1391C0();
        }
    }
}

// .text:0x001391C0 size:0x540 mapped:0x80778254
void fn_3_1391C0(void) {
    return;
}

// .text:0x00138AA4 size:0x71C mapped:0x80777B38
void fn_3_138AA4(void) {
    return;
}

// .text:0x001384B4 size:0x5F0 mapped:0x80777548
void fn_3_1384B4(Unk3520Obj* obj) {
    return;
}

// .text:0x00138448 size:0x6C mapped:0x807774DC
void fn_3_138448(Unk3520Obj* obj) {
    if (g_Minigame._72A == 0) {
        if (obj->_3A < 0x7FFE) {
            obj->_3A++;
        } else {
            obj->_3A = 0x7FFF;
        }
        if (obj->_3A >= obj->_38) {
            obj->_3E = 0;
            fn_3_1384B4(obj);
        }
    }
}

// .text:0x001382E0 size:0x168 mapped:0x80777374
void fn_3_1382E0(Unk3520Obj* obj) {
    u32 t;
    u32 minutes;

    t = minutes = g_Minigame._17C0 / 60 / 20;

    if (g_Minigame._72A != 0) {
        Unk3520Obj_SetDelay(obj, minutes);
    } else {
        if (obj->_3A < 0x7FFE) {
            obj->_3A++;
        } else {
            obj->_3A = 0x7FFF;
        }
        if (t > 3) {
            t = 3;
        }
        if (obj->_3A / 60 >= lbl_3_data_21AD0[lbl_3_bss_B781[0]][t]) {
            obj->_C.x = obj->_C.z = 0.0f;
            obj->_C.y = -lbl_3_data_21A64[1];
            obj->_3D = 2;
            obj->_3A = 0;
        }
    }
}

// .text:0x0013802C size:0x2B4 mapped:0x807770C0
void fn_3_13802C(void) {
    return;
}

// .text:0x00137F14 size:0x118 mapped:0x80776FA8
void fn_3_137F14(Unk3520Obj* obj) {
    if (g_Minigame._72A != 0) {
        obj->_C.y = lbl_3_data_21A64[5];
        obj->_3D = 5;
        obj->_3A = 0;
    } else {
        if (obj->_3E != 0) {
            obj->_3F++;
            if (obj->_3F >= 10) {
                fn_3_90064(0x303);
                obj->_3E = 0;
            }
        }
        if (obj->_3A < 0x7FFE) {
            obj->_3A++;
        } else {
            obj->_3A = 0x7FFF;
        }
        if (!fn_3_137B10(obj) && obj->_3A >= lbl_3_data_21A64[6]) {
            obj->_C.y = lbl_3_data_21A64[5];
            obj->_3D = 5;
            obj->_3A = 0;
        }
    }
}

// .text:0x00137DE4 size:0x130 mapped:0x80776E78
void fn_3_137DE4(Unk3520Obj* obj) {
    u32 t;

    PSVECAdd(&obj->_0, &obj->_C, &obj->_0);
    PSVECAdd(&obj->_18, &obj->_24, &obj->_18);
    if (obj->_3A < 0x7FFE) {
        obj->_3A++;
    } else {
        obj->_3A = 0x7FFF;
    }
    if (obj->_3A >= lbl_3_data_21A64[7]) {
        t = g_Minigame._17C0 / 60 / 20;
        if (t > 3) {
            t = 3;
        }
        Unk3520Obj_SetDelay(obj, t);
    }
}

// .text:0x00137CF8 size:0xEC mapped:0x80776D8C
void fn_3_137CF8(Unk3520Obj* obj) {
    u32 t;

    PSVECAdd(&obj->_0, &obj->_C, &obj->_0);
    if (!fn_3_137B10(obj) && obj->_0.y >= lbl_3_data_21A64[0]) {
        t = g_Minigame._17C0 / 60 / 20;
        if (t > 3) {
            t = 3;
        }
        Unk3520Obj_SetDelay(obj, t);
    }
}

// .text:0x00137B10 size:0x1E8 mapped:0x80776BA4
u8 fn_3_137B10(Unk3520Obj* obj) {
    int i;
    u8 hit = FALSE;
    Unk3520Fielder* fielder;
    f32 top;
    f32 range;
    f32 dx;
    f32 dz;
    Vec v;

    for (i = 0; i < 4; i++) {
        if (g_Minigame.minigameFielderIndex[i] < 0) {
            continue;
        }
        if (g_Minigame.starDashStunType[i] != 0 && g_Minigame.starDashStunType[i] != 3) {
            continue;
        }
        if (obj->_3D != 2 && i != g_Minigame._1D6D) {
            continue;
        }
        fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
        top = fielder->_15C + (fielder->_00C + fielder->pos.y);
        range = top < obj->_0.y ? fielder->_16C : 12.0f;
        if (range < fabs(top - obj->_0.y)) {
            continue;
        }
        dx = fabs(obj->_0.x - fielder->pos.x);
        dz = fabs(obj->_0.z - fielder->pos.z);
        if (dx <= 3.5f && dz <= 3.125f) {
            if (i == g_Minigame._1D6D) {
                if (!hit) {
                    v.x = fielder->_038;
                    v.z = fielder->_03C;
                    v.y = 0.0f;
                    hit = TRUE;
                    PSVECScale(&v, lbl_3_data_21A64[2], &v);
                    v.y = lbl_3_data_21A64[3];
                    memcpy(&obj->_C, &v, sizeof(Vec));
                    obj->_24.x = lbl_3_data_21A64[4];
                    obj->_3A = 0;
                    obj->_3D = 4;
                }
            } else {
                g_Minigame.starDashStunType[i] = 1;
                g_Minigame._1CB8[i].x = fielder->pos.x - obj->_0.x;
                g_Minigame._1CB8[i].z = fielder->pos.z - obj->_0.z;
                obj->_3E = 1;
                obj->_3F = 0;
            }
        }
    }
    return hit;
}

// .text:0x001379A0 size:0x170 mapped:0x80776A34
BOOL fn_3_1379A0(int fielderIdx) {
    Unk3520Fielder* fielder = &g_Fielders[fielderIdx];
    u32 player;
    u32 i;
    Unk3520Obj* obj;
    f32 top;
    f32 range;
    f32 dx;
    f32 dz;

    for (player = 0; player < 4; player++) {
        if (g_Minigame.minigameFielderIndex[player] == fielderIdx) {
            break;
        }
    }
    if (player == g_Minigame._1D6D) {
        return FALSE;
    }
    for (i = 0; i < lbl_3_bss_B780; i++) {
        obj = &MG.objs[i];
        if (obj->_3D != 3 && obj->_3D != 5) {
            continue;
        }
        top = fielder->_15C + (fielder->_00C + fielder->pos.y);
        range = top < obj->_0.y ? fielder->_16C : 12.0f;
        if (range < fabs(top - obj->_0.y)) {
            continue;
        }
        dx = fabs(obj->_0.x - (fielder->pos.x + fielder->_030));
        dz = fabs(obj->_0.z - (fielder->pos.z + fielder->_034));
        if (dx < 3.5f && dz < 3.125f) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x001373E0 size:0x5C0 mapped:0x80776474
void fn_3_1373E0(void) {
    return;
}

// .text:0x00137224 size:0x1BC mapped:0x807762B8
void fn_3_137224(void) {
    return;
}

// .text:0x001371E8 size:0x3C mapped:0x8077627C
void fn_3_1371E8(void) {
    lbl_3_bss_B702 = lbl_3_data_21AF0[0];
    fn_800528AC(fn_3_1370A0);
}

// .text:0x001370A0 size:0x148 mapped:0x80776134
void fn_3_1370A0(camera_803c639c_s* camera) {
    Vec shake;
    Mtx inv;

    memset(&shake, 0, sizeof(Vec));
    shake.y = lbl_3_data_21AF4 * (2.0 * (rand() / 32767.0f - 0.5));
    PSMTXInverse(camera->view, inv);
    PSMTXMultVecSR(inv, &shake, &shake);
    camera->eye.x += shake.x;
    camera->eye.y += shake.y;
    camera->eye.z += shake.z;
    camera->target.x += shake.x;
    camera->target.y += shake.y;
    camera->target.z += shake.z;
    if (--lbl_3_bss_B702 <= 0) {
        lbl_3_bss_B702 = 0;
        fn_800528B4();
    }
}

// .text:0x00136EA4 size:0x1FC mapped:0x80775F38
void fn_3_136EA4(void) {
    if (g_Minigame.turnOverStatus != 0) {
        g_Minigame.playerIDWithPowerup[0] = -1;
        MG.box._1E = 0;
    } else if (MG.box._1E != 0) {
        fn_3_13688C(&MG.box);
    } else {
        fn_3_136CF4(&MG.box);
    }
}

// .text:0x00136CF4 size:0x1B0 mapped:0x80775D88
void fn_3_136CF4(Unk3520Box* box) {
    s8 chance;
    f32 angle;

    if (g_Minigame.playerIDWithPowerup[0] != -1) {
        if (--g_Minigame._1D58 <= 0) {
            if (g_Minigame._1D6D != g_Minigame.playerIDWithPowerup[0]) {
                fn_800115C8(g_Minigame.playerIDWithPowerup[0]);
            }
            g_Minigame.playerIDWithPowerup[0] = -1;
        }
    } else {
        box->_1C--;
        if (box->_1C <= 0) {
            chance = rand() % 100 - lbl_3_data_21B16;
            if (chance < 0) {
                box->_1E = 1;
            } else {
                box->_1E = 2;
            }
            box->pos.x = lbl_3_data_219AC.x;
            box->pos.y = lbl_3_data_219AC.y;
            box->pos.z = lbl_3_data_219AC.z;
            box->vel.y = lbl_3_data_21AF8[0];
            angle = 0.017453292f * (360.0f * (rand() / 32767.0f));
            box->vel.x = lbl_3_data_21AF8[1] * cosf_kludge(angle);
            box->vel.z = lbl_3_data_21AF8[1] * sinf_kludge(angle);
            box->_1C = lbl_3_data_21B10[1];
        }
    }
}

// .text:0x0013688C size:0x468 mapped:0x80775920
void fn_3_13688C(Unk3520Box* box) {
    return;
}

// .text:0x00136220 size:0x66C mapped:0x807752B4
void fn_3_136220(void) {
    return;
}

// .text:0x001360BC size:0x164 mapped:0x80775150
void fn_3_1360BC(int player) {
    Unk3520Fielder* fielder;
    int count;
    int i;
    int n;
    f32 speed;
    s16 angle;

    fielder = &g_Fielders[g_Minigame.minigameFielderIndex[player]];
    g_Minigame._1DF4_arr[player] = 1;
    count = lbl_3_data_21B20[3];
    if (g_Minigame.miniGameCurrentPoints[player] < count) {
        count = g_Minigame.miniGameCurrentPoints[player];
    }
    if (count == 0) {
        return;
    }
    for (i = 0, n = 0; i < 50; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] == 0) {
            g_Minigame.wallBall_coinCoordinates[i].x = fielder->pos.x;
            g_Minigame.wallBall_coinCoordinates[i].y = fielder->pos.y;
            g_Minigame.wallBall_coinCoordinates[i].z = fielder->pos.z;
            g_Minigame.wallBall_coinCoordinates[i].y = fielder->_16C;
            g_Minigame.wallBall_coinVelocity[i].y = lbl_3_data_219B8[18];
            angle = random_fn_3_9EE24(0x1000);
            getComponentsFromSAng(angle, &g_Minigame.wallBall_coinVelocity[i].x, &g_Minigame.wallBall_coinVelocity[i].z);
            speed = RandomF32_Game_Range(lbl_3_data_219B8[16], lbl_3_data_219B8[17]);
            g_Minigame.wallBall_coinVelocity[i].x *= speed;
            g_Minigame.wallBall_coinVelocity[i].z *= speed;
            g_Minigame.wallBall_coinsVisibleInd[i] = 1;
            g_Minigame.wallBall_coinsVisibleFrameCounter[i] = 0;
            g_Minigame._1D6C++;
            n++;
            if (n >= count) {
                break;
            }
        }
    }
    fn_3_90064(0x2E8);
    g_Minigame.miniGameCurrentPoints[player] -= count;
}

// .text:0x00136048 size:0x74 mapped:0x807750DC
void fn_3_136048(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        g_Minigame._1D64[i] += lbl_3_data_21A44;
        g_Minigame._1D64[i] = fn_3_9FE6C_normalizeAngle(g_Minigame._1D64[i]);
    }
}

// .text:0x00135FF4 size:0x54 mapped:0x80775088
void fn_3_135FF4(void) {
    u32 frame = lbl_3_data_21A3C[g_Minigame._1D73][0] * 60;

    if (frame == g_Minigame._17C0) {
        g_Minigame._1D72 = 1;
        g_Minigame._1D62 = 0;
        g_Minigame._1D48 = 0.0f;
        g_Minigame._1D73++;
    }
}

// .text:0x00135F4C size:0xA8 mapped:0x80774FE0
void fn_3_135F4C(void) {
    g_Minigame._1D62++;
    g_Minigame._1D48 = (f32)g_Minigame._1D62 / (f32)lbl_3_data_21A60._0;
    fn_3_135C18();
    if (g_Minigame._1D62 >= lbl_3_data_21A60._0) {
        g_Minigame._1D72 = 2;
    }
}

// .text:0x00135E98 size:0xB4 mapped:0x80774F2C
void fn_3_135E98(void) {
    g_Minigame._1D62++;
    g_Minigame._1D48 = 1.0f - (f32)g_Minigame._1D62 / (f32)lbl_3_data_21A60._0;
    fn_3_135C18();
    if (g_Minigame._1D62 >= lbl_3_data_21A60._0) {
        g_Minigame._1D72 = 0;
    }
}

// .text:0x00135E38 size:0x60 mapped:0x80774ECC
void fn_3_135E38(void) {
    u32 frame;

    fn_3_135C18();
    frame = lbl_3_data_21A3C[g_Minigame._1D73 - 1][1] * 60;
    if (frame == g_Minigame._17C0) {
        g_Minigame._1D72 = 3;
        g_Minigame._1D62 = 0;
    }
}

// .text:0x00135C18 size:0x220 mapped:0x80774CAC
void fn_3_135C18(void) {
    f32 inner;
    f32 outer;
    f32 step;
    f32 t;
    f32 x;
    f32 z;
    int i;
    int j;
    int k;

    inner = g_Minigame._1D48 * lbl_3_data_21A54[1] - lbl_3_data_21A54[0];
    step = (lbl_3_data_21A54[1] - lbl_3_data_21A54[0]) / lbl_3_data_21A60._2;
    outer = inner + lbl_3_data_21A54[0];
    for (i = 0, k = 0; i < 4; i++) {
        getComponentsFromSAng(g_Minigame._1D64[i], &x, &z);
        t = inner;
        MG.spokes[i].start.x = x * lbl_3_data_21A54[0] + lbl_3_data_21A48.x;
        MG.spokes[i].start.z = z * lbl_3_data_21A54[0] + lbl_3_data_21A48.z;
        MG.spokes[i].end.x = x * outer + lbl_3_data_21A48.x;
        MG.spokes[i].end.z = z * outer + lbl_3_data_21A48.z;
        x = (MG.spokes[i].end.x - MG.spokes[i].start.x) / inner;
        z = (MG.spokes[i].end.z - MG.spokes[i].start.z) / inner;
        for (j = 0; j < lbl_3_data_21A60._2; j++, k++) {
            MG.pieces[k].pos.x = x * t + MG.spokes[i].start.x;
            MG.pieces[k].pos.z = z * t + MG.spokes[i].start.z;
            if (t < 0.0f) {
                MG.pieces[k]._26 = 0;
            } else {
                t -= step;
                if (MG.pieces[k]._26 != 0) {
                    fn_3_156548(k, MG.pieces[k].pos.x, -MG.pieces[k].pos.y, MG.pieces[k].pos.z);
                } else {
                    fn_3_15730C(k, MG.pieces[k].pos.x, -MG.pieces[k].pos.y, MG.pieces[k].pos.z);
                    MG.pieces[k]._26 = 1;
                }
            }
        }
    }
}

// .text:0x00135A64 size:0x1B4 mapped:0x80774AF8
void fn_3_135A64(void) {
    int i;
    int j;
    Unk3520Fielder* fielder;
    int angle;
    f32 dist;

    if (g_Minigame.turnOverStatus == 0 && !(g_Minigame._1D48 < 0.3f)) {
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameFielderIndex[i] < 0) {
                continue;
            }
            if (i == g_Minigame._1D6D) {
                continue;
            }
            if (g_Minigame.starDashStunType[i] != 0) {
                continue;
            }
            fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
            if (fielder->_203 != 0 && fielder->_204 > 3) {
                continue;
            }
            angle = fn_3_9FB8C(fielder->pos.x - lbl_3_data_219AC.x, fielder->pos.z - lbl_3_data_219AC.z);
            for (j = 0; j < 4; j++) {
                if (fn_3_9FCF8(angle, g_Minigame._1D64[j]) > 0x200) {
                    continue;
                }
                dist = fn_3_9EFD0(&MG.spokes[j].start, &MG.spokes[j].end, (VecXYZ*)&fielder->pos, NULL);
                if (dist < lbl_3_data_21A54[2] + lbl_3_data_47BC[fielder->_1C9] && dist >= 0.0f) {
                    fn_3_1360BC(i);
                    g_Minigame.starDashStunType[i] = 3;
                    g_Minigame._1D5A[i] = 0;
                    fn_3_25844(g_Minigame.minigameFielderIndex[i], 2);
                    fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[i], 2);
                    break;
                }
            }
        }
    }
}

// .text:0x00135924 size:0x140 mapped:0x807749B8
void fn_3_135924(void) {
    u32 i;

    for (i = 0; i < 100; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i] == 1 && g_Minigame.wallBall_coinCoordinates[i].y < 3.0f) {
            fn_3_13583C((Vec*)&g_Minigame.wallBall_coinCoordinates[i]);
        }
    }
}

// .text:0x0013583C size:0xE8 mapped:0x807748D0
void fn_3_13583C(Vec* pos) {
    Vec center = { 0.0f, 0.0f, 20.0f };
    Vec d;

    if (pos != NULL) {
        PSVECSubtract(pos, &center, &d);
        d.y = 0.0f;
        if (PSVECMag(&d) <= 3.5f) {
            fn_3_1357A4(pos, &d);
        }
    }
}

// .text:0x001357A4 size:0x98 mapped:0x80774838
void fn_3_1357A4(Vec* pos, Vec* dir) {
    Vec base = { 0.0f, 0.0f, 20.0f };
    Vec n;

    if (!pos || !dir) {
        return;
    }
    PSVECNormalize(dir, &n);
    PSVECScale(&n, 3.5f, &n);
    pos->x = base.x + n.x;
    pos->z = base.z + n.z;
}

// .text:0x001356F8 size:0xAC mapped:0x8077478C
void fn_3_1356F8(void) {
    Unk3520Cpu* cpu = (Unk3520Cpu*)&g_Minigame._1DCC;
    u8 strength;
    u32 i;

    memset(g_Minigame._1D7C, 0, 0x78);
    for (i = 0; i < 4; cpu++, i++) {
        strength = g_Minigame.minigameControlStruct.aIStrength[i];
        cpu->_4 = -1;
        cpu->_0 = RandomInt_Game(100) < lbl_3_data_21B88[strength] ? 3.0f : 1.5f;
    }
}

// .text:0x00135698 size:0x60 mapped:0x8077472C
int fn_3_135698(const void* a, const void* b) {
    if (((Unk3520Sort*)a)->_11 != 0 && ((Unk3520Sort*)b)->_11 == 0) {
        return -1;
    }
    if (((Unk3520Sort*)a)->_11 == 0 && ((Unk3520Sort*)b)->_11 != 0) {
        return 1;
    }
    if (((Unk3520Sort*)a)->_0 < ((Unk3520Sort*)b)->_0) {
        return -1;
    }
    return ((Unk3520Sort*)a)->_0 > ((Unk3520Sort*)b)->_0;
}

// .text:0x0013564C size:0x4C mapped:0x807746E0
int fn_3_13564C(f32 x, f32 z) {
    if (x >= 0.0f) {
        if (z >= 0.0f) {
            return 0;
        }
        return 3;
    }
    if (z >= 0.0f) {
        return 1;
    }
    return 2;
}

// .text:0x00135600 size:0x4C mapped:0x80774694
void fn_3_135600(f32* outX, f32* outZ, f32 x, f32 z) {
    x -= lbl_3_data_21A48.x;
    z -= lbl_3_data_21A48.z;
    *outX = x * g_Minigame._1DF0 - z * g_Minigame._1DEC;
    *outZ = x * g_Minigame._1DEC + z * g_Minigame._1DF0;
}

// .text:0x00135520 size:0xE0 mapped:0x807745B4
int fn_3_135520(f32 x, f32 z, f32 r) {
    if (x >= 0.0f) {
        if (z >= 0.0f) {
            if (z <= r) {
                return 1;
            }
            if (x <= r) {
                return 2;
            }
        } else {
            if (x <= r) {
                return 1;
            }
            if (z >= -r) {
                return 2;
            }
        }
    } else {
        if (z >= 0.0f) {
            if (x >= -r) {
                return 1;
            }
            if (z <= r) {
                return 2;
            }
        } else {
            if (z >= -r) {
                return 1;
            }
            if (x >= -r) {
                return 2;
            }
        }
    }
    return 0;
}

// .text:0x001354BC size:0x64 mapped:0x80774550
// 98.0%: dx and dz come out of fabs in swapped FPRs, and the index scaling in another
// register; MG.objs[i] scores 82%.
BOOL fn_3_1354BC(s32 i, f32 x, f32 z) {
    BOOL ret = FALSE;
    f32 dx = fabs(((Unk3520Obj*)((u8*)&g_Minigame + 0xBB0))[i]._0.x - x);
    f32 dz = fabs(((Unk3520Obj*)((u8*)&g_Minigame + 0xBB0))[i]._0.z - z);

    if (dx <= 4.7f && dz <= 4.325f) {
        ret = TRUE;
    }
    return ret;
}

// .text:0x001350BC size:0x400 mapped:0x80774150
void fn_3_1350BC(void) {
    return;
}

// .text:0x00134D4C size:0x370 mapped:0x80773DE0
void fn_3_134D4C(void) {
    return;
}

// .text:0x00134C80 size:0xCC mapped:0x80773D14
void fn_3_134C80(void) {
    return;
}

// .text:0x0013493C size:0x344 mapped:0x807739D0
void fn_3_13493C(void) {
    return;
}

// .text:0x00134918 size:0x24 mapped:0x807739AC
int fn_3_134918(const void* a, const void* b) {
    if (((Unk3520Sort*)a)->_0 < ((Unk3520Sort*)b)->_0) {
        return -1;
    }
    return ((Unk3520Sort*)a)->_0 > ((Unk3520Sort*)b)->_0;
}

// .text:0x00134908 size:0x10 mapped:0x8077399C
int fn_3_134908(const void* a, const void* b) {
    return ((Unk3520Sort*)b)->_4 - ((Unk3520Sort*)a)->_4;
}

// .text:0x00134658 size:0x2B0 mapped:0x807736EC
void fn_3_134658(void) {
    return;
}

// .text:0x001345AC size:0xAC mapped:0x80773640
s16 fn_3_1345AC(s16 angle, s16 target, int speed) {
    s16 step;

    if (angle < 0 || target < 0) {
        return target;
    }
    step = fn_3_9FCA4(target, angle) / lbl_3_data_21B8C[speed];
    if (step == 0 || __abs(step) > 1500) {
        return target;
    }
    return fn_3_9FE6C_normalizeAngle(angle + step);
}

// .text:0x001344BC size:0xF0 mapped:0x80773550
BOOL fn_3_1344BC(int a, int b) {
    f32 ax = g_Fielders[g_Minigame.minigameFielderIndex[a]].pos.x - lbl_3_data_21A48.x;
    f32 az = g_Fielders[g_Minigame.minigameFielderIndex[a]].pos.z - lbl_3_data_21A48.z;
    f32 bx = g_Fielders[g_Minigame.minigameFielderIndex[b]].pos.x - lbl_3_data_21A48.x;
    f32 bz = g_Fielders[g_Minigame.minigameFielderIndex[b]].pos.z - lbl_3_data_21A48.z;
    f32 angA = atan2(az, ax);
    f32 angB = atan2(bz, bx);

    return fn_3_9FCA4(radToShortAngle(angA), radToShortAngle(angB)) >= 0;
}

// .text:0x0013334C size:0x1170 mapped:0x807723E0
void fn_3_13334C(void) {
    return;
}

// .text:0x00133320 size:0x2C mapped:0x807723B4
void fn_3_133320(void) {
    s8 i;

    i = 0;
    do {
        g_Minigame._1DC8[i] = 0;
    } while (++i < 4);
}

// .text:0x00133200 size:0x120 mapped:0x80772294
void fn_3_133200(void) {
    u32 y;
    u32 x;
    u32 offset;

    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            offset = fn_800247E4(x, y, 4, 4);
            if (offset < 32) {
                lbl_3_bss_B740[offset + 0] = lbl_3_bss_B740[offset + 2] = 255;
                lbl_3_bss_B740[offset + 1] = lbl_3_bss_B740[offset + 3] = 150;
            } else {
                lbl_3_bss_B740[offset + 0] = lbl_3_bss_B740[offset + 2] = 150;
                lbl_3_bss_B740[offset + 1] = lbl_3_bss_B740[offset + 3] = 150;
            }
        }
    }
    GXInitTexObj(&lbl_3_bss_B708, lbl_3_bss_B740, 4, 4, GX_TF_RGBA8, GX_REPEAT, GX_REPEAT, GX_FALSE);
    GXInitTexObjLOD(&lbl_3_bss_B708, GX_LINEAR, GX_LINEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    lbl_3_data_26580 = -1;
    lbl_3_bss_B704 = 0;
}

// .text:0x001330E4 size:0x11C mapped:0x80772178
void fn_3_1330E4(void) {
    int value;
    int i;

    lbl_3_bss_B704 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_B704 & 1) == 0) {
        value = lbl_3_bss_B740[fn_800247E4(0, 0, 4, 4)];
        value += lbl_3_data_26580 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            lbl_3_bss_B740[i] = value;
        }
        DCFlushRange(lbl_3_bss_B740, 0x40);
        if (value + lbl_3_data_26580 * 2 > 255 || value + lbl_3_data_26580 * 2 < 0) {
            lbl_3_data_26580 *= -1;
        }
    }
}

// .text:0x00132EDC size:0x208 mapped:0x80771F70
void fn_3_132EDC(void* arg0, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* arg4, u8* arg5) {
    int value;
    int i;

    lbl_3_bss_B704 += (lbl_80366158._28 == 0);
    if ((lbl_3_bss_B704 & 1) == 0) {
        value = lbl_3_bss_B740[fn_800247E4(0, 0, 4, 4)];
        value += lbl_3_data_26580 * 2;
        if (value > 255) {
            value = 255;
        } else if (value < 0) {
            value = 0;
        }
        for (i = 0; i < 32; i += 2) {
            lbl_3_bss_B740[i] = value;
        }
        DCFlushRange(lbl_3_bss_B740, 0x40);
        if (value + lbl_3_data_26580 * 2 > 255 || value + lbl_3_data_26580 * 2 < 0) {
            lbl_3_data_26580 *= -1;
        }
    }
    GXLoadTexObj(&lbl_3_bss_B708, *map);
    GXSetTexCoordGen2(*coord, GX_TG_MTX2X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetTevOrder(*stage, *coord, *map, GX_COLOR_NULL);
    GXSetTevColorIn(*stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_TEXA, GX_CC_CPREV);
    GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    (*stage)++;
    (*coord)++;
    (*map)++;
    (*arg4)++;
    (*arg5)++;
}
