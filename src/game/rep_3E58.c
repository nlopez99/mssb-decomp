#include "game/rep_3E58.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
// in .rodata, so MWCC does not pool .rodata and addresses constants one by one
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "Dolphin/mtx.h"
#include "Dolphin/rand.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u32 _00;
    /* 0x04 */ s32 _04;
    /* 0x08 */ s32 _08;
    /* 0x0C */ s32 _0C;
    /* 0x10 */ Vec _10;
    /* 0x1C */ f32 _1C;
    /* 0x20 */ f32 _20;
    /* 0x24 */ f32 _24;
    /* 0x28 */ f32 _28;
    /* 0x2C */ f32 _2C;
    /* 0x30 */ f32 _30;
    /* 0x34 */ f32 _34;
    /* 0x38 */ u32 _38;
    /* 0x3C */ u32 _3C;
    /* 0x40 */ Vec _40;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 _4F;
} UnkParticle3E58; // size: 0x50

typedef struct UnkPlayer3E58 {
    /* 0x000 */ u8 _000[0x44];
    /* 0x044 */ f32 _044;
    /* 0x048 */ u8 _048[0x62 - 0x48];
    /* 0x062 */ s16 _062;
    /* 0x064 */ u8 _064[0x254 - 0x64];
    /* 0x254 */ s8 _254;
} UnkPlayer3E58;

typedef struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ UnkPlayer3E58* _14;
    /* 0x18 */ s16 _18;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
} UnkTask3E58;

extern struct {
    /* 0x000 */ u8 _000[0x479];
    /* 0x479 */ u8 _479;
} lbl_3_common_bss_35154;

typedef struct {
    /* 0x00 */ u8 _00[4];
    /* 0x04 */ Vec _04;
    /* 0x10 */ u8 _10[0x28 - 0x10];
} UnkMarker3E58; // size: 0x28

extern struct {
    /* 0x0000 */ u8 _0000[0x2D90];
    /* 0x2D90 */ UnkMarker3E58* _2D90;
} lbl_8036E548;

extern u32 lbl_803CBD0C;
extern void* lbl_803CC1B8;

UnkParticle3E58 lbl_3_data_28508 = {
    0, 0x20, 1, 0x24,
    { 0.0f, 0.0f, 0.0f },
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.25f,
    0xFF, 0,
    { 0.0f, 0.0f, 0.0f },
    0xFF, 0xFF, 0xFF, 0,
};

u8 lbl_3_data_28558[0x18] = {
    0x04, 0x05, 0x06, 0x07, 0x08, 0x10, 0x11, 0x12, 0x13, 0x14, 0x16, 0x17,
    0x18, 0x19, 0x1A, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x00,
};

static s8 lbl_3_bss_B9E0;

extern BOOL fn_8001B728(s32, s32, Vec*);
extern void fn_80026998(UnkParticle3E58*);
extern void fn_800B0A14_removeQueue(void);
extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);

// .text:0x001682AC size:0x168 mapped:0x807A7340
void fn_3_1682AC(UnkPlayer3E58* player, s8 type) {
    UnkTask3E58* task = NULL;

    if (player != NULL) {
        switch (type) {
        case 1:
            task = fn_800B0A5C_insertQueue(fn_3_1680D4, 0xFFFA);
            break;
        case 2:
            task = fn_800B0A5C_insertQueue(fn_3_167F14, 0xFFFA);
            break;
        case 4:
            task = fn_800B0A5C_insertQueue(fn_3_167CC4, 0xFFFA);
            break;
        case 3:
            task = fn_800B0A5C_insertQueue(fn_3_167D4C, 0xFFFA);
            break;
        case 10:
            task = fn_800B0A5C_insertQueue(fn_3_1678A8, 0xFFFA);
            break;
        case 8:
            task = fn_800B0A5C_insertQueue(fn_3_1674D0, 0xFFFA);
            break;
        case 6:
            task = fn_800B0A5C_insertQueue(fn_3_166FCC, 0xFFFA);
            break;
        case 12:
            task = fn_800B0A5C_insertQueue(fn_3_167178, 0xFFFA);
            break;
        case 11:
            task = fn_800B0A5C_insertQueue(fn_3_166E04, 0xFFFA);
            break;
        case 7:
            task = fn_800B0A5C_insertQueue(fn_3_166D40, 0xFFFA);
            break;
        }
        if (task != NULL) {
            task->_14 = player;
            task->_18 = 0;
            task->_1A = type;
            task->_1B = 0;
        }
    }
}

// .text:0x001680D4 size:0x1D8 mapped:0x807A7168
void fn_3_1680D4(void) {
    UnkTask3E58* task = lbl_803CC1B8;
    UnkPlayer3E58* player;
    s8 id;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2) {
        fn_800B0A14_removeQueue();
    } else if (task->_14->_062 == 0x26 || task->_14->_062 == 0x28 || task->_14->_062 == 0x29 || task->_14->_062 == 0x2A ||
               task->_14->_062 == 0x2B || task->_14->_062 == 0x2C) {
        id = lbl_3_data_28558[rand() % (sizeof(lbl_3_data_28558) - 1)];
        player = task->_14;
        fn_3_166C30(player, id);
        task->_1B = 1;
    } else if (task->_1B != 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00167F14 size:0x1C0 mapped:0x807A6FA8
void fn_3_167F14(void) {
    UnkTask3E58* task = lbl_803CC1B8;
    UnkPlayer3E58* player;
    s8 id;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2) {
        fn_800B0A14_removeQueue();
    } else if (task->_14->_062 == 0x26) {
        id = lbl_3_data_28558[rand() % (sizeof(lbl_3_data_28558) - 1)];
        player = task->_14;
        fn_3_166C30(player, id);
        task->_1B = 1;
    } else if (task->_1B != 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00167D4C size:0x1C8 mapped:0x807A6DE0
void fn_3_167D4C(void) {
    UnkTask3E58* task = lbl_803CC1B8;
    UnkPlayer3E58* player;
    s8 id;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2) {
        fn_800B0A14_removeQueue();
    } else if (task->_14->_062 == 0x1B || task->_14->_062 == 0x1A) {
        id = lbl_3_data_28558[rand() % (sizeof(lbl_3_data_28558) - 1)];
        player = task->_14;
        fn_3_166C30(player, id);
        task->_1B = 1;
    } else if (task->_1B != 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00167CC4 size:0x88 mapped:0x807A6D58
void fn_3_167CC4(void) {
    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2) {
        fn_800B0A14_removeQueue();
    } else if (g_Ball.ballState == 2) {
        fn_3_16699C();
    } else {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x001678A8 size:0x41C mapped:0x807A693C
void fn_3_1678A8(void) {
    UnkTask3E58* task = lbl_803CC1B8;
    UnkParticle3E58 particle;
    u32 i;
    f32 angle;
    f32 speed;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2) {
        fn_800B0A14_removeQueue();
    } else if ((task->_14->_062 >= 8 && task->_14->_062 <= 0xE) || (task->_14->_062 >= 0x11 && task->_14->_062 <= 0x1B)) {
        Vec pos = { 0.0f, 0.0f, 0.0f };
        Vec dir;

        memcpy(&particle, &lbl_3_data_28508, sizeof(UnkParticle3E58));
        // A one-pass loop: the target loads every float constant into a saved
        // register before the body, as loop-invariant code motion does
        for (i = 0; i < 1; i++) {
            particle._00 = lbl_803CBD0C;
            particle._34 = particle._30;
            angle = 0.0f;
            angle += 45.0 * (2.0 * (rand() / 32767.0f - 0.5));
            angle -= 57.29578f * task->_14->_044;
            angle = 0.017453292f * angle;
            dir.x = -sinf_kludge(angle);
            dir.y = 1.0f;
            dir.z = cosf_kludge(angle);
            speed = 0.1f + 0.03f * (2.0 * (rand() / 32767.0f - 0.5));
            dir.x *= speed;
            dir.z *= speed;
            speed = 0.1f + 0.03f * (2.0 * (rand() / 32767.0f - 0.5));
            dir.y *= speed;
            memcpy(&particle._10, &dir, sizeof(Vec));
            particle._1C = 1.0f;
            particle._28 = 0.0f;
            particle._20 = 0.0f;
            particle._24 = 1.0f;
            particle._2C = -0.0044f;
            fn_8001B728(task->_14->_254, (s8)lbl_3_data_28558[rand() % (sizeof(lbl_3_data_28558) - 1)], &pos);
            memcpy(&particle._40, &pos, sizeof(Vec));
            memset(&pos, 0, sizeof(Vec));
            particle._4C = rand() % 256;
            particle._4D = rand() % 256;
            particle._4E = rand() % 256;
            fn_80026998(&particle);
        }
        task->_1B = 1;
    } else if (task->_1B != 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x001674D0 size:0x3D8 mapped:0x807A6564
void fn_3_1674D0(void) {
    UnkTask3E58* task = lbl_803CC1B8;
    UnkParticle3E58 particle;
    Mtx inv;
    u32 i;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2) {
        fn_800B0A14_removeQueue();
    } else if (task->_14->_062 == 0x1B || task->_14->_062 == 0x1A) {
        if (g_Ball.ballState == 0) {
            Vec offset = { 0.0f, 0.0f, 0.0f };
            Vec pos;
            Vec dir;

            fn_8001B728(task->_14->_254, 0x2F, &offset);
            pos.x = -1.0f * -sinf_kludge(-task->_14->_044);
            pos.z = -1.0f * cosf_kludge(-task->_14->_044);
            pos.y = -g_Ball.AtBat_Contact_BallPos.y - offset.y;
            pos.x = 5.0f * pos.x * (task->_18 / 10.0f);
            pos.z = 5.0f * pos.z * (task->_18 / 10.0f);
            pos.y = pos.y * (task->_18 / 10.0f);
            PSVECAdd(&pos, &offset, &pos);
            memcpy(&particle, &lbl_3_data_28508, sizeof(UnkParticle3E58));
            particle._00 = lbl_803CBD0C;
            PSMTXInverse(fn_80052768_getCamera(0)->view, inv);
            for (i = 0; i < 5; i++) {
                dir.x = 0.5f * (2.0f * (rand() / 32767.0f - 0.5f));
                dir.y = 0.5f * (2.0f * (rand() / 32767.0f - 0.5f));
                dir.z = 0.0f;
                PSMTXMultVecSR(inv, &dir, &dir);
                PSVECAdd(&dir, &pos, &dir);
                memcpy(&particle._40, &dir, sizeof(Vec));
                particle._4C = rand() % 256;
                particle._4D = rand() % 256;
                particle._4E = rand() % 256;
                fn_80026998(&particle);
            }
        } else {
            fn_800B0A14_removeQueue();
        }
        task->_1B = 1;
        task->_18++;
    } else if (task->_1B != 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00167178 size:0x358 mapped:0x807A620C
void fn_3_167178(void) {
    UnkTask3E58* task = lbl_803CC1B8;
    UnkParticle3E58 particle;
    Mtx inv;
    Vec pos = { 0.0f, 0.0f, 0.0f };
    Vec dir;
    u32 i;
    f32 angle;
    f32 speed;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2) {
        fn_800B0A14_removeQueue();
    } else {
        fn_8001B728(task->_14->_254, 4, &pos);
        PSMTXInverse(fn_80052768_getCamera(0)->view, inv);
        memcpy(&particle, &lbl_3_data_28508, sizeof(UnkParticle3E58));
        memcpy(&particle._40, &pos, sizeof(Vec));
        particle._00 = lbl_803CBD0C;
        particle._34 = particle._30;
        for (i = 0; i < 20; i++) {
            angle = 18.0 * i;
            angle += 9.0 * (2.0 * (rand() / 32767.0f - 0.5));
            angle = 0.017453292f * angle;
            dir.x = cosf_kludge(angle);
            dir.y = sinf_kludge(angle);
            dir.z = 0.0f;
            PSMTXMultVecSR(inv, &dir, &dir);
            speed = 0.03f * (2.0 * (rand() / 32767.0f - 0.5)) + 0.1f;
            memcpy(&particle._10, &dir, sizeof(Vec));
            particle._1C = speed;
            particle._4C = rand() % 256;
            particle._4D = rand() % 256;
            particle._4E = rand() % 256;
            fn_80026998(&particle);
        }
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00166FCC size:0x1AC mapped:0x807A6060
void fn_3_166FCC(void) {
    UnkTask3E58* task = lbl_803CC1B8;
    UnkPlayer3E58* player;
    s8 id;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2) {
        fn_800B0A14_removeQueue();
    } else if (task->_14->_062 == 0x26 || task->_14->_062 == 0x27) {
        // Arguments of the inlined fn_3_166C30 in locals, for the target's register allocation
        id = lbl_3_data_28558[rand() % (sizeof(lbl_3_data_28558) - 1)];
        player = task->_14;
        fn_3_166C30(player, id);
    } else {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00166E04 size:0x1C8 mapped:0x807A5E98
void fn_3_166E04(void) {
    UnkTask3E58* task = lbl_803CC1B8;
    UnkPlayer3E58* player;
    s8 id;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2) {
        fn_800B0A14_removeQueue();
    } else if (task->_14->_062 == 0x22 || (g_Ball.ballState == 1 && (task->_14->_062 == 5 || task->_14->_062 == 7))) {
        id = lbl_3_data_28558[rand() % (sizeof(lbl_3_data_28558) - 1)];
        player = task->_14;
        fn_3_166C30(player, id);
    } else {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00166D40 size:0xC4 mapped:0x807A5DD4
void fn_3_166D40(void) {
    UnkTask3E58* task = lbl_803CC1B8;

    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2) {
        fn_800B0A14_removeQueue();
    } else if ((task->_14->_062 == 0x1B || task->_14->_062 == 0x1A) && g_Ball.ballState == 0) {
        fn_3_16699C();
        task->_1B = 1;
    } else if (task->_1B != 0) {
        fn_800B0A14_removeQueue();
    }
}

// .text:0x00166C30 size:0x110 mapped:0x807A5CC4
void fn_3_166C30(UnkPlayer3E58* player, s8 id) {
    UnkParticle3E58 particle;
    Vec pos;

    memset(&pos, 0, sizeof(Vec));
    memcpy(&particle, &lbl_3_data_28508, sizeof(UnkParticle3E58));
    particle._00 = lbl_803CBD0C;
    if (!fn_8001B728(player->_254, id, &pos)) {
        memset(&pos, 0, sizeof(Vec));
        fn_8001B728(player->_254, 4, &pos);
    }
    memcpy(&particle._40, &pos, sizeof(Vec));
    particle._4C = rand() % 256;
    particle._4D = rand() % 256;
    particle._4E = rand() % 256;
    fn_80026998(&particle);
}

// .text:0x0016699C size:0x294 mapped:0x807A5A30
void fn_3_16699C(void) {
    UnkParticle3E58 particle;
    Mtx inv;
    Vec offset;
    Vec pos;
    UnkMarker3E58* marker;

    memset(&offset, 0, sizeof(Vec));
    memcpy(&particle, &lbl_3_data_28508, sizeof(UnkParticle3E58));
    particle._00 = lbl_803CBD0C;
    offset.x = 2.0f * (rand() / 32767.0f - 0.5f);
    offset.y = 0.5f * (2.0f * (rand() / 32767.0f - 0.5f));
    PSMTXInverse(fn_80052768_getCamera(0)->view, inv);
    PSMTXMultVecSR(inv, &offset, &offset);

    switch (g_Ball.currentStarSwing) {
    case 5:
        marker = &lbl_8036E548._2D90[7];
        break;
    case 6:
        marker = &lbl_8036E548._2D90[7];
        break;
    case 7:
        marker = &lbl_8036E548._2D90[10];
        break;
    case 8:
        marker = &lbl_8036E548._2D90[11];
        break;
    case 9:
        marker = &lbl_8036E548._2D90[8];
        break;
    case 10:
        marker = &lbl_8036E548._2D90[9];
        break;
    default:
        marker = &lbl_8036E548._2D90[0];
        break;
    }

    memcpy(&pos, &marker->_04, sizeof(Vec));
    offset.x += pos.x;
    offset.y += pos.y;
    offset.z += pos.z;
    memcpy(&particle._40, &offset, sizeof(Vec));
    particle._4C = rand() % 256;
    particle._4D = rand() % 256;
    particle._4E = rand() % 256;
    fn_80026998(&particle);
}

// .text:0x0016696C size:0x30 mapped:0x807A5A00
void fn_3_16696C(void) {
    fn_800B0A5C_insertQueue(fn_3_16689C, 0xFFFA);
}

// .text:0x0016689C size:0xD0 mapped:0x807A5930
void fn_3_16689C(void) {
    if (g_d_GameSettings._55 != 0 || lbl_3_common_bss_35154._479 != 0) {
        fn_800B0A14_removeQueue();
    } else if (g_GameLogic.gameStatus != 2 || g_GameLogic.framesOfExitingToMenu != 0 || g_Ball.fielderWBallIndex < 0) {
        fn_800B0A14_removeQueue();
    } else if (g_d_GameSettings.GameModeSelected == 6 && g_Minigame.TF_ballDespawnedInd) {
        fn_800B0A14_removeQueue();
    } else if (g_Ball.ballState != 1) {
        fn_800B0A14_removeQueue();
    } else {
        fn_3_16699C();
    }
}

// .text:0x001666B0 size:0x1EC mapped:0x807A5744
void fn_3_1666B0(Vec* src) {
    UnkParticle3E58 particle;
    Vec pos;

    if (++lbl_3_bss_B9E0 >= 5) {
        memset(&particle, 0, sizeof(UnkParticle3E58));
        memcpy(&particle, &lbl_3_data_28508, sizeof(UnkParticle3E58));
        memcpy(&pos, src, sizeof(Vec));
        particle._34 = 0.2f * particle._30;
        if (pos.y > 0.0f) {
            pos.y *= -1.0f;
        }
        lbl_3_bss_B9E0 = 0;
        particle._00 = lbl_803CBD0C;
        pos.x += 5.0f * (rand() / 32767.0f - 0.5f);
        pos.y -= 3.0f * (rand() / 32767.0f);
        pos.z -= 0.45f;
        memcpy(&particle._40, &pos, sizeof(Vec));
        particle._4C = rand() % 256;
        particle._4D = rand() % 256;
        particle._4E = rand() % 256;
        fn_80026998(&particle);
    }
}
