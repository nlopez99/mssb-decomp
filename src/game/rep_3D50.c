#include "game/rep_3D50.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "string.h"

typedef struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u16 _12;
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
} UnkTask3D50;

typedef struct {
    /* 0x00 */ s32 _00;
    /* 0x04 */ s32 _04[15];
} UnkEffect3D50; // size: 0x40

extern struct {
    /* 0x000 */ u8 _000[0x4];
    /* 0x004 */ s32 _004;
    /* 0x008 */ u8 _008[0x440 - 0x8];
    /* 0x440 */ Vec _440;
    /* 0x44C */ Vec _44C;
    /* 0x458 */ Vec _458;
    /* 0x464 */ s16 _464;
    /* 0x466 */ u8 _466;
    /* 0x467 */ u8 _467[0x479 - 0x467];
    /* 0x479 */ u8 _479;
    /* 0x47A */ u16 _47A[2];
} lbl_3_common_bss_35154;

extern struct {
    /* 0x00 */ u8 _00[0x28];
    /* 0x28 */ u8 _28;
} lbl_80366158;

extern UnkTask3D50* lbl_803CC1B8;

typedef struct {
    /* 0x0 */ u8 _0;
    /* 0x1 */ u8 _1; // index into starMissionCompletionTracker.characters
    /* 0x2 */ u8 _2; // index into lbl_80109AE8
    /* 0x3 */ u8 _3[3];
} UnkCharEntry3D50; // size: 0x6

extern UnkCharEntry3D50 lbl_800E8558[54];

typedef struct {
    /* 0x0 */ s16 type;
    /* 0x2 */ s16 target;
    /* 0x4 */ s16 flags;
    /* 0x6 */ u8 _6[4];
} UnkMissionDef3D50; // size: 0xA

extern UnkMissionDef3D50 lbl_80109AE8[32][10];

// The status of the character's mission i in the current game: counts up, -1 once completed
#define MISSION_STATUS(id, i) starMissionCompletionTracker.characters[id].inGameMissionTracker[i].starMissionStatus

UnkEffect3D50 lbl_3_data_281F0[8] = {
    { 0, { 4, 3, 110000, 1000, 90000, 40, 1, 102000, 101000, 100, 10000000, 0xFFFF0000, 0, 50000, 20000 } },
    { 0, { 4, 3, 110000, 1000, 90000, 40, 1, 102000, 101000, 100, 10000000, 0xFFFF0000, 0, 50000, 20000 } },
    { 0, { 4, 12, 200000, 1000, 90000, 40, 1, 102000, 101000, 100, 10000000, 0xFFFF0000, 0, 50000, 20000 } },
    { 0, { 4, 1, 90000, 111000, 90000, 40, 1, 102000, 101000, 100, 10000000, 0xFFFF0000, 0, 50000, 20000 } },
    { 0, { 4, 3, 110000, 1000, 90000, 40, 1, 102000, 101000, 100, 10000000, 0xB559FF00, 0, 50000, 20000 } },
    { 0, { 4, 3, 110000, 1000, 90000, 40, 1, 102000, 101000, 100, 10000000, 0xB559FF00, 0, 50000, 20000 } },
    { 0, { 4, 12, 200000, 1000, 90000, 40, 1, 102000, 101000, 100, 10000000, 0xB559FF00, 0, 50000, 20000 } },
    { 0, { 4, 1, 70000, 1000, 90000, 40, 1, 102000, 101000, 100, 10000000, 0xB559FF00, 0, 50000, 20000 } },
};

s32 lbl_3_data_283F0[2][4] = {
    { 10, 10, 10, 10 },
    { 10, 10, 10, 1 },
};

s32 lbl_3_data_28410[2] = { 40, 40 };

// Unreferenced: the target's .bss runs to 0xB9E0, past what MWCC's 8-byte section alignment pads.
static u8 lbl_3_bss_B9BC[0x24];
static UnkTask3D50* lbl_3_bss_B9B8;

extern void fn_8002C2D0(Vec* pos, Vec* dir, UnkEffect3D50* effect);
extern void fn_800B0A14_removeQueue(void);
extern UnkTask3D50* fn_800B0A5C_insertQueue(void (*)(void), u16);

// .text:0x00161078 size:0x510 mapped:0x807A010C
// 95.90%: the prologue allocates differently (player in r0 where the target keeps it in r10,
// the entry pointer and the id/set loads in other registers); the loops match apart from that.
void fn_3_161078(void) {
    s32 player = g_d_GameSettings._35;
    u8* place = &g_Minigame.minigameControlStruct._1C[player];
    s16* points = &g_Minigame.miniGameCurrentPoints[player];
    u8 difficulty = g_d_GameSettings.challengeDifficulty;
    u8 mode = g_Minigame.GameMode_MiniGame;
    u8* time = &g_Minigame._1CB1[player];
    u8 id = lbl_800E8558[g_Minigame.minigameControlStruct._4[player]]._1;
    u8 set = lbl_800E8558[g_Minigame.minigameControlStruct._4[player]]._2;
    s32 j;
    s32 beaten;
    s32 count;
    s32 i;
    s32 k;
    s32 anyMode;
    s32 inMode;
    s32 target;
    UnkMissionDef3D50* def;

    for (i = 0; i < 10; i++) {
        def = &lbl_80109AE8[set][i];
        if (MISSION_STATUS(id, i) == -2) {
            continue;
        }
        if (MISSION_STATUS(id, i) == -1) {
            if (def->flags & 2) {
                if (difficulty < 1) {
                    MISSION_STATUS(id, i) = 0;
                }
            } else if (def->flags & 4) {
                if (difficulty < 2) {
                    MISSION_STATUS(id, i) = 0;
                }
            } else if (def->flags & 8) {
                if (difficulty < 3) {
                    MISSION_STATUS(id, i) = 0;
                }
            }
            if ((def->flags & 1) && *place != 1) {
                MISSION_STATUS(id, i) = 0;
            }
            continue;
        }
        if (def->flags & 2) {
            if (difficulty < 1) {
                continue;
            }
        } else if (def->flags & 4) {
            if (difficulty < 2) {
                continue;
            }
        } else if (def->flags & 8) {
            if (difficulty < 3) {
                continue;
            }
        }
        if ((def->flags & 1) && *place != 1) {
            continue;
        }
        anyMode = FALSE;
        inMode = FALSE;
        for (k = 0; k < 7; k++) {
            if (def->flags & (0x10 << k)) {
                anyMode = TRUE;
                if (mode == k) {
                    inMode = TRUE;
                }
            }
        }
        if (anyMode && !inMode) {
            continue;
        }
        switch (def->type) {
            case 47:
                if (*place <= def->target) {
                    MISSION_STATUS(id, i) = -1;
                }
                break;
            case 48:
                target = def->target;
                if (mode == 1 || mode == 3) {
                    target *= 100;
                } else if (mode == 0 || mode == 2) {
                    target *= 10;
                }
                if (*points >= target) {
                    MISSION_STATUS(id, i) = -1;
                }
                break;
            case 49:
                beaten = count = 0;
                for (j = 0; j < 4; j++) {
                    if (g_Minigame.minigameControlStruct.characterIndex[j] >= 0 && j != player &&
                        def->target == lbl_800E8558[g_Minigame.minigameControlStruct._4[j]]._2) {
                        count++;
                        if (*place < g_Minigame.minigameControlStruct._1C[j]) {
                            beaten++;
                        }
                    }
                }
                if (count != 0 && beaten == count && *place == 1) {
                    MISSION_STATUS(id, i) = -1;
                }
                break;
            case 54:
                if (mode == 5 && *time <= def->target) {
                    MISSION_STATUS(id, i) = -1;
                }
                break;
        }
    }
    for (i = 0; i < 54; i++) {
        for (j = 0; j < 10; j++) {
            if (MISSION_STATUS(i, j) <= -1) {
                MISSION_STATUS(i, j) = -2;
            } else {
                MISSION_STATUS(i, j) = 0;
            }
        }
    }
}

// .text:0x001608F0 size:0x788 mapped:0x8079F984
void fn_3_1608F0(int event, int value, int flag) {
    s32 i;
    s32 found = FALSE;
    u8 set;
    u8 id;

    id = lbl_800E8558[g_Minigame.minigameControlStruct._4[g_d_GameSettings._35]]._1;
    set = lbl_800E8558[g_Minigame.minigameControlStruct._4[g_d_GameSettings._35]]._2;
    switch (event) {
        case 0:
            for (i = 0; i < 10; i++) {
                if (MISSION_STATUS(id, i) >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 50:
                            if (value >= lbl_80109AE8[set][i].target) {
                                found = TRUE;
                                goto done;
                            }
                            break;
                    }
                }
            }
            break;
        case 1:
            for (i = 0; i < 10; i++) {
                if (MISSION_STATUS(id, i) >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 51:
                            if (flag) {
                                MISSION_STATUS(id, i)++;
                                if (MISSION_STATUS(id, i) >= lbl_80109AE8[set][i].target) {
                                    found = TRUE;
                                    goto done;
                                }
                            } else {
                                MISSION_STATUS(id, i) = 0;
                            }
                            break;
                    }
                }
            }
            break;
        case 2:
            for (i = 0; i < 10; i++) {
                if (MISSION_STATUS(id, i) >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 52:
                            if (flag >= 15) {
                                MISSION_STATUS(id, i)++;
                                if (MISSION_STATUS(id, i) >= lbl_80109AE8[set][i].target) {
                                    found = TRUE;
                                    goto done;
                                }
                            }
                            break;
                    }
                }
            }
            break;
        case 3:
            for (i = 0; i < 10; i++) {
                if (MISSION_STATUS(id, i) >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 53:
                            if (value == 2) {
                                MISSION_STATUS(id, i)++;
                                if (MISSION_STATUS(id, i) >= lbl_80109AE8[set][i].target) {
                                    found = TRUE;
                                    goto done;
                                }
                            }
                            break;
                    }
                }
            }
            break;
        case 5:
            for (i = 0; i < 10; i++) {
                if (MISSION_STATUS(id, i) >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 55:
                            if (value == 4) {
                                MISSION_STATUS(id, i)++;
                                if (MISSION_STATUS(id, i) >= lbl_80109AE8[set][i].target) {
                                    found = TRUE;
                                    goto done;
                                }
                            }
                            break;
                    }
                }
            }
            break;
        case 6:
            for (i = 0; i < 10; i++) {
                if (MISSION_STATUS(id, i) >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 56:
                            MISSION_STATUS(id, i)++;
                            if (MISSION_STATUS(id, i) >= lbl_80109AE8[set][i].target) {
                                found = TRUE;
                                goto done;
                            }
                            break;
                    }
                }
            }
            break;
        case 7:
            for (i = 0; i < 10; i++) {
                if (MISSION_STATUS(id, i) >= 0) {
                    switch (lbl_80109AE8[set][i].type) {
                        case 57:
                            if (value == lbl_80109AE8[set][i].target) {
                                found = TRUE;
                                goto done;
                            }
                            break;
                    }
                }
            }
            break;
    }
done:
    if (found) {
        MISSION_STATUS(id, i) = -1;
    }
}

// .text:0x00160814 size:0xDC mapped:0x8079F8A8
void fn_3_160814(s32 type) {
    s32* times;

    if (lbl_3_common_bss_35154._464 == 0) {
        lbl_3_bss_B9B8 = fn_800B0A5C_insertQueue(fn_3_160578, lbl_803CC1B8->_12 + 1);
        lbl_3_bss_B9B8->_14 = type == 4;
        times = lbl_3_data_283F0[lbl_3_bss_B9B8->_14];
        lbl_3_bss_B9B8->_15 = 0;
        lbl_3_bss_B9B8->_16 = times[0];
        lbl_3_bss_B9B8->_17 = 0;
        lbl_3_common_bss_35154._47A[lbl_3_bss_B9B8->_14 != 0] = lbl_3_data_28410[lbl_3_bss_B9B8->_14];
    }
}

// .text:0x00160578 size:0x29C mapped:0x8079F60C
void fn_3_160578(void) {
    Vec pos;
    Vec diff;
    UnkTask3D50* task = lbl_803CC1B8;
    s32 idx;

    if (g_d_GameSettings._55 || lbl_3_common_bss_35154._479) {
        fn_800B0A14_removeQueue();
        return;
    }
    if (lbl_3_common_bss_35154._466 == 0) {
        lbl_3_bss_B9B8 = NULL;
        fn_800B0A14_removeQueue();
        return;
    }
    if (lbl_80366158._28 != 0) {
        return;
    }
    if (task->_15 == 0 && g_Ball.warioWaluGarlicIsActive) {
        task->_15 = 1;
        task->_17 = 0;
    }
    if (task->_17 != 0) {
        task->_17--;
        return;
    }
    if (task->_15 == 0) {
        idx = g_GameLogic.bOD_framesInLiveBallScene >= 0;
    } else if (task->_15 == 1) {
        task->_15 = 2;
        idx = 2;
    } else {
        idx = 3;
    }
    if (task->_14) {
        idx += 4;
    }
    PSVECSubtract(&lbl_3_common_bss_35154._44C, &lbl_3_common_bss_35154._440, &diff);
    if (PSVECMag(&diff)) {
        lbl_3_data_281F0[idx]._00 = lbl_3_common_bss_35154._004;
        fn_8002C2D0(&lbl_3_common_bss_35154._440, &diff, &lbl_3_data_281F0[idx]);
    }
    pos.x = g_Ball.warioStarHitCoords[2].x;
    pos.y = -g_Ball.warioStarHitCoords[2].y;
    pos.z = g_Ball.warioStarHitCoords[2].z;
    if (idx % 4 == 3) {
        PSVECSubtract(&lbl_3_common_bss_35154._458, &pos, &diff);
        if (PSVECMag(&diff)) {
            if (g_Ball.framesUntilBallHitsGround == lbl_3_common_bss_35154._47A[task->_14 != 0]) {
                idx--;
            }
            fn_8002C2D0(&pos, &diff, &lbl_3_data_281F0[idx]);
        }
    }
    if (task->_15 == 2) {
        memcpy(&lbl_3_common_bss_35154._458, &pos, sizeof(Vec));
    }
    task->_17 = task->_16;
    if (task->_16 != 0) {
        task->_16--;
    }
}
