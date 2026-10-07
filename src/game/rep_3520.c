#include "game/rep_3520.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "game/rep_540.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

// One of four objects at g_Minigame + 0xBB0
typedef struct Unk3520Obj {
    /* 0x00 */ Vec _0;
    /* 0x0C */ Vec _C;
    /* 0x18 */ u8 _18[0x24 - 0x18];
    /* 0x24 */ f32 _24;
    /* 0x28 */ u8 _28[0x30 - 0x28];
    /* 0x30 */ f32 _30;
    /* 0x34 */ f32 _34;
    /* 0x38 */ s16 _38;
    /* 0x3A */ s16 _3A;
    /* 0x3C */ u8 _3C;
    /* 0x3D */ u8 _3D;
    /* 0x3E */ u8 _3E;
    /* 0x3F */ u8 _3F;
} Unk3520Obj; // size: 0x40

#define OBJS ((Unk3520Obj*)((u8*)&g_Minigame + 0xBB0))

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
    /* 0x010 */ u8 _010[0x38 - 0x10];
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ u8 _040[0x15C - 0x40];
    /* 0x15C */ f32 _15C;
    /* 0x160 */ u8 _160[0x16C - 0x160];
    /* 0x16C */ f32 _16C;
    /* 0x170 */ u8 _170[0x268 - 0x170];
} Unk3520Fielder; // size: 0x268

extern Unk3520Fielder g_Fielders[9];

extern void fn_3_5A6D4(u8 status);
extern void fn_3_10F550(u8, s16);
extern void changeScene(u8, s16);

extern u8 lbl_3_data_21278[2];
extern f32 lbl_3_data_219B8[19];
extern s16 lbl_3_data_21A04[8];
extern s16 lbl_3_data_21A3C[2][2];
extern s16 lbl_3_data_21A44;
extern Vec lbl_3_data_21A48;
extern s16 lbl_3_data_21A60;
extern f32 lbl_3_data_21A64[9];
extern s16 lbl_3_data_21A90[4][4][2];
extern s16 lbl_3_data_21AF0[1];
extern s8 lbl_3_data_21B88[4];
extern s16 lbl_3_data_21B8C[4];

u8 lbl_3_data_26580 = 0xFF;

// .bss statics, declared in reverse address order (MWCC lays them out last to first)
static u8 lbl_3_bss_B781[1];
static u8 lbl_3_bss_B780;
static u8 lbl_3_bss_B740[0x40] ATTRIBUTE_ALIGN(32);
static GXTexObj lbl_3_bss_B708;
static u32 lbl_3_bss_B704;
static s16 lbl_3_bss_B702;
static u8 lbl_3_bss_B700;

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
    return;
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
    return;
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
    return;
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
void fn_3_1382E0(void) {
    return;
}

// .text:0x0013802C size:0x2B4 mapped:0x807770C0
void fn_3_13802C(void) {
    return;
}

// .text:0x00137F14 size:0x118 mapped:0x80776FA8
void fn_3_137F14(void) {
    return;
}

// .text:0x00137DE4 size:0x130 mapped:0x80776E78
void fn_3_137DE4(void) {
    return;
}

// .text:0x00137CF8 size:0xEC mapped:0x80776D8C
void fn_3_137CF8(Unk3520Obj* obj) {
    u32 t;
    s16 lo;
    int r;

    PSVECAdd(&obj->_0, &obj->_C, &obj->_0);
    if (!fn_3_137B10(obj) && obj->_0.y >= lbl_3_data_21A64[0]) {
        t = g_Minigame._17C0 / 60 / 20;
        if (t > 3) {
            t = 3;
        }
        obj->_3D = 0;
        obj->_3A = 0;
        lo = lbl_3_data_21A90[g_Minigame.soloMinigameDifficulty][t][0];
        r = random_fn_3_9EE24((lbl_3_data_21A90[g_Minigame.soloMinigameDifficulty][t][1] - lo) * 60);
        obj->_38 = r + lo * 60;
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
                    obj->_24 = lbl_3_data_21A64[4];
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
void fn_3_1379A0(void) {
    return;
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
    return;
}

// .text:0x00136EA4 size:0x1FC mapped:0x80775F38
void fn_3_136EA4(void) {
    return;
}

// .text:0x00136CF4 size:0x1B0 mapped:0x80775D88
void fn_3_136CF4(void) {
    return;
}

// .text:0x0013688C size:0x468 mapped:0x80775920
void fn_3_13688C(void) {
    return;
}

// .text:0x00136220 size:0x66C mapped:0x807752B4
void fn_3_136220(void) {
    return;
}

// .text:0x001360BC size:0x164 mapped:0x80775150
void fn_3_1360BC(void) {
    return;
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
    if (lbl_3_data_21A3C[g_Minigame._1D73][0] * 60 == g_Minigame._17C0) {
        g_Minigame._1D72 = 1;
        g_Minigame._1D62 = 0;
        g_Minigame._1D48 = 0.0f;
        g_Minigame._1D73++;
    }
}

// .text:0x00135F4C size:0xA8 mapped:0x80774FE0
void fn_3_135F4C(void) {
    g_Minigame._1D62++;
    g_Minigame._1D48 = (f32)g_Minigame._1D62 / (f32)lbl_3_data_21A60;
    fn_3_135C18();
    if (g_Minigame._1D62 >= lbl_3_data_21A60) {
        g_Minigame._1D72 = 2;
    }
}

// .text:0x00135E98 size:0xB4 mapped:0x80774F2C
void fn_3_135E98(void) {
    g_Minigame._1D62++;
    g_Minigame._1D48 = 1.0f - (f32)g_Minigame._1D62 / (f32)lbl_3_data_21A60;
    fn_3_135C18();
    if (g_Minigame._1D62 >= lbl_3_data_21A60) {
        g_Minigame._1D72 = 0;
    }
}

// .text:0x00135E38 size:0x60 mapped:0x80774ECC
void fn_3_135E38(void) {
    fn_3_135C18();
    if (lbl_3_data_21A3C[g_Minigame._1D73 - 1][1] * 60 == g_Minigame._17C0) {
        g_Minigame._1D72 = 3;
        g_Minigame._1D62 = 0;
    }
}

// .text:0x00135C18 size:0x220 mapped:0x80774CAC
void fn_3_135C18(void) {
    return;
}

// .text:0x00135A64 size:0x1B4 mapped:0x80774AF8
void fn_3_135A64(void) {
    return;
}

// .text:0x00135924 size:0x140 mapped:0x807749B8
void fn_3_135924(void) {
    return;
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
BOOL fn_3_1354BC(s32 i, f32 x, f32 z) {
    BOOL ret = FALSE;
    f32 dz;
    f32 dx;

    dx = fabs(OBJS[i]._0.x - x);
    dz = fabs(OBJS[i]._0.z - z);
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
    return;
}

// .text:0x001330E4 size:0x11C mapped:0x80772178
void fn_3_1330E4(void) {
    return;
}

// .text:0x00132EDC size:0x208 mapped:0x80771F70
void fn_3_132EDC(void) {
    return;
}
