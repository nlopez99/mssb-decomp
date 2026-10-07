#include "game/rep_3290.h"
// Must precede header_rep_data.h, which keeps the .rodata constants unpooled as in the target
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "game/rep_3880.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/rand.h"
#include "string.h"

typedef struct {
    /* 0x000 */ VecXYZ _000;
    /* 0x00C */ u8 _00C[0x30 - 0xC];
    /* 0x030 */ f32 _030;
    /* 0x034 */ f32 _034;
    /* 0x038 */ f32 _038;
    /* 0x03C */ f32 _03C;
    /* 0x040 */ u8 _040[0x50 - 0x40];
    /* 0x050 */ f32 _050;
    /* 0x054 */ u8 _054[0x268 - 0x54];
} Unk3290Fielder; // size: 0x268

extern Unk3290Fielder g_Fielders[9];
extern struct {
    /* 0x00 */ s32 _00;
} g_Scores;

extern s16 lbl_3_data_5F3C[4];
extern f32 lbl_3_data_450C[18];
extern VecXZ lbl_3_data_21500[4];
extern VecXYZ lbl_3_data_21520[2][7];
extern VecXYZ lbl_3_data_215C8[2];
extern VecXYZ lbl_3_data_215E0[7];
extern f32 lbl_3_data_21634[5];
extern u32 lbl_3_data_21648[3];
extern s16 lbl_3_data_21654[12];
extern f32 lbl_3_data_21674[2];
extern s16 lbl_3_data_2167C[6];
extern f32 lbl_3_data_21688[3];
extern s8 lbl_3_data_21694[4][7];
extern s8 lbl_3_data_216B0[4][2];
extern s8 lbl_3_data_216B8[4];
extern f32 lbl_3_data_219B8[19];

// m_sound.h declares this as void(void).
extern void fn_3_90064(int id);
extern void fn_8004C108(VecXYZ* pos, int arg1);
extern void fn_800246D4(int (*compare)(const void*, const void*), void* src, void* dst, int size, int count);

// .text:0x00114A88 size:0x538 mapped:0x80753B1C
void fn_3_114A88(BOOL instant) {
    int i;
    int slot;
    Unk3290Fielder* fielder;
    f32 t;
    f32 dx;
    f32 dz;

    if (++g_Minigame.wallBallPitcherRotationCounter == 1 || instant) {
        if (g_Minigame.soloMinigameDifficulty != MINIGAME_DIFFICULTY_SOLO_NON_CHALLENGE || g_Minigame.multiPlayerInd) {
            g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._14[(g_Minigame.turnNumberWithinRound + 3) % 4]]]._000.x = g_Minigame.wallBallSomeXPos;
            g_Fielders[g_Minigame.minigameFielderIndex[g_Minigame.minigameControlStruct._14[(g_Minigame.turnNumberWithinRound + 3) % 4]]]._000.z = g_Minigame.wallBallSomeZPos;
        }
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                slot = i - g_Minigame.turnNumberWithinRound;
                if (slot < 0) {
                    slot += g_Minigame.miniGameNumberOfParticipants;
                }
                if (slot == 0) {
                    g_Minigame.wallBallWaitingLocations[g_Minigame.minigameControlStruct._14[i]].x = lbl_3_data_450C[0];
                    g_Minigame.wallBallWaitingLocations[g_Minigame.minigameControlStruct._14[i]].z = lbl_3_data_450C[1];
                } else {
                    g_Minigame.wallBallWaitingLocations[g_Minigame.minigameControlStruct._14[i]].x = lbl_3_data_21500[slot].x;
                    g_Minigame.wallBallWaitingLocations[g_Minigame.minigameControlStruct._14[i]].z = lbl_3_data_21500[slot].z;
                }
            }
        }
        if (instant) {
            for (i = 0; i < g_Minigame.miniGameNumberOfParticipants; i++) {
                fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
                fielder->_000.x = g_Minigame.wallBallWaitingLocations[i].x;
                fielder->_000.y = 0.0f;
                fielder->_000.z = g_Minigame.wallBallWaitingLocations[i].z;
            }
            return;
        }
    }
    if (g_Minigame.wallBallPitcherRotationCounter >= lbl_3_data_2167C[1]) {
        g_Minigame.wallBallRotatePitchersInd = FALSE;
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                g_Fielders[g_Minigame.minigameFielderIndex[i]]._050 = 0.0f;
            }
        }
    } else {
        t = 1.0f / (lbl_3_data_2167C[1] - g_Minigame.wallBallPitcherRotationCounter);
        for (i = 0; i < 4; i++) {
            if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0) {
                fielder = &g_Fielders[g_Minigame.minigameFielderIndex[i]];
                dx = g_Minigame.wallBallWaitingLocations[i].x - fielder->_000.x;
                dx *= t;
                dz = g_Minigame.wallBallWaitingLocations[i].z - fielder->_000.z;
                dz *= t;
                fielder->_030 = dx;
                fielder->_034 = dz;
                fielder->_000.x += dx;
                fielder->_000.z += dz;
                fielder->_050 = dolsqrtf2(dx * dx + dz * dz);
                if (fielder->_050 > 0.0f) {
                    fielder->_038 = dx / fielder->_050;
                    fielder->_03C = dx / fielder->_050; // dx, not dz, in the original too
                }
            }
        }
    }
}

// .text:0x00114A2C size:0x5C mapped:0x80753AC0
void fn_3_114A2C(void) {
    if (g_Minigame.wallBallGameState == WALL_BALL_GAME_STATE_CALCULATE_NEW_WALLS) {
        fn_3_114384();
        fn_3_1500C8();
    } else if (g_Minigame.wallBallGameState == WALL_BALL_GAME_STATE_DROP_IN_NEW_WALLS) {
        fn_3_114204();
    } else if (g_Minigame.wallBallGameState == WALL_BALL_GAME_STATE_PITCH_OR_WAITING_FOR_PITCH) {
        fn_3_113F14();
        fn_3_113D20();
    }
}

// .text:0x001149B8 size:0x74 mapped:0x80753A4C
int fn_3_1149B8(const void* a, const void* b) {
    MaybeWallBallStruct* wallA = &g_Minigame.wallBallWalls[*(u8*)a];
    MaybeWallBallStruct* wallB = &g_Minigame.wallBallWalls[*(u8*)b];

    if (wallA->_28 == 3 && wallB->_28 != 3) {
        return -1;
    }
    if (wallA->_28 != 3 && wallB->_28 == 3) {
        return 1;
    }
    return wallA->wallPos - wallB->wallPos;
}

// .text:0x00114384 size:0x634 mapped:0x80753418
void fn_3_114384(void) {
    int limit;
    u32 i;
    u8 n;
    u32 j;
    int k;
    u32 standing;
    u32 counts[3];
    u32 candidates[7];
    u8 positions[7];
    u8 pick;
    int m;
    MaybeWallBallStruct* wall;

    if (g_Minigame.multiPlayerInd || g_Minigame._1A3C || g_Minigame.soloMinigameDifficulty != MINIGAME_DIFFICULTY_SOLO_NON_CHALLENGE) {
        switch (g_Scores._00) {
        case 1:
            limit = 1;
            break;
        case 2:
            limit = 2;
            break;
        default:
            limit = 3;
            break;
        }
    } else if (g_Minigame.miniGameTurnCounter < 6) {
        limit = 1;
    } else if (g_Minigame.miniGameTurnCounter < 11) {
        limit = 2;
    } else if (g_Minigame.miniGameTurnCounter < 16) {
        limit = 3;
    } else {
        limit = 4;
    }
    fn_800246D4(fn_3_1149B8, g_Minigame.wallIndexTracker, g_Minigame.wallIndexTracker, 1, 7);
    i = 0;
    do {
        g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].wallPos = i;
    } while (++i < 7);
    i = 0;
    do {
        counts[i] = 0;
    } while (++i < 3);
    standing = 0;
    i = 0;
    do {
        wall = &g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]];
        if (wall->_28 == 3) {
            standing++;
            counts[wall->coinGenerationCategory]++;
        }
    } while (++i < 7);
    i = 0;
    do {
        wall = &g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]];
        VEC_COPY(&wall->_C, &lbl_3_data_21520[0][wall->wallPos]);
        if (i < standing) {
            wall->_28 = 2;
        } else {
            VEC_COPY(&wall->_0, &wall->_C);
            VEC_ADD(&wall->_0, &wall->_0, &lbl_3_data_21520[1][wall->wallPos]);
            wall->_28 = 1;
            wall->coinGenerationCategory = 1;
            counts[wall->coinGenerationCategory]++;
            wall->_24 = lbl_3_data_21654[wall->coinGenerationCategory + 4];
        }
        wall->_26 = 0;
        wall->_18 = 0.0f;
        wall->_1C = 0.0f;
        wall->_20 = 0.0f;
    } while (++i < 7);
    if (standing < 7) {
        if (counts[2] == 0) {
            n = 0;
            for (i = standing; i < 7; i++) {
                j = 0;
                do {
                    if (i == g_Minigame.wallBallSpecialWallPos[j]) {
                        break;
                    }
                } while (++j < 2);
                if (j >= 2) {
                    positions[n++] = i;
                }
            }
            if (n) {
                pick = positions[RandomInt_Game(n)];
            } else {
                pick = RandomInt_Game_Range(standing, 6);
            }
            wall = &g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[pick]];
            wall->coinGenerationCategory = 2;
            wall->_24 = lbl_3_data_21654[wall->coinGenerationCategory + 4];
            counts[1]--;
        }
        if (counts[1] > limit) {
            m = 0;
            for (i = standing; i < 7; i++) {
                if (g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].coinGenerationCategory != 2 &&
                    (i == 0 || g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i - 1]].coinGenerationCategory != 2) &&
                    (i == 6 || limit <= 1 || g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i + 1]].coinGenerationCategory != 2)) {
                    candidates[m] = i;
                    m++;
                }
            }
            if (m != 0) {
                while (counts[1] > limit) {
                    k = RandomInt_Game(m);
                    wall = &g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[candidates[k]]];
                    wall->coinGenerationCategory = 0;
                    wall->_24 = lbl_3_data_21654[wall->coinGenerationCategory + 4];
                    counts[1]--;
                    for (i = k; i < m - 1; i++) {
                        candidates[i] = candidates[i + 1];
                    }
                    if (--m <= 0) {
                        break;
                    }
                }
            }
        }
    }
    i = 0;
    do {
        g_Minigame.wallBallSpecialWallPos[i + 1] = g_Minigame.wallBallSpecialWallPos[i];
    } while (++i < 1);
    i = 0;
    do {
        if (g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].coinGenerationCategory == 2) {
            g_Minigame.wallBallSpecialWallPos[0] = i;
            break;
        }
    } while (++i < 7);
    g_Minigame.wallBallGameState = WALL_BALL_GAME_STATE_DROP_IN_NEW_WALLS;
    g_Minigame._1A80 = 7;
}

// .text:0x00114204 size:0x180 mapped:0x80753298
void fn_3_114204(void) {
    int i;
    int count = 0;
    MaybeWallBallStruct* wall;

    for (i = 0; i < 7; i++) {
        wall = &g_Minigame.wallBallWalls[i];
        if (wall->_28 == 2) {
            VEC_ADD(&wall->_0, &wall->_0, &lbl_3_data_215C8[1]);
            if (wall->_0.z >= wall->_C.z) {
                wall->_0.z = wall->_C.z;
                wall->_28 = 3;
            }
            count++;
        }
    }
    if (count == 0) {
        for (i = 0; i < 7; i++) {
            wall = &g_Minigame.wallBallWalls[i];
            if (wall->_28 == 1) {
                VEC_ADD(&wall->_0, &wall->_0, &lbl_3_data_215C8[0]);
                if (wall->_0.y <= wall->_C.y) {
                    wall->_0.y = wall->_C.y;
                    wall->_28 = 3;
                    fn_8004C108(&wall->_C, 1);
                    fn_3_90064(0x2F4);
                }
                count++;
            }
        }
        if (count == 0) {
            g_Minigame.wallBallGameState = WALL_BALL_GAME_STATE_PITCH_OR_WAITING_FOR_PITCH;
        }
    }
}

// .text:0x00113F14 size:0x2F0 mapped:0x80752FA8
void fn_3_113F14(void) {
    MaybeWallBallStruct* wall;
    int i;
    int j;
    u8 count;
    f32 angle;

    if (g_Ball.pitchHangtimeCounter >= 1) {
        for (i = 0; i < 7; i++) {
            wall = &g_Minigame.wallBallWalls[i];
            if (wall->_28 == 3 &&
                g_Ball.AtBat_Contact_BallPos.z - g_Ball.groundYForBounces - lbl_3_data_21674[1] <= wall->_0.z &&
                !g_Minigame.ballStoppedBreakingWallsInd) {
                wall->_24 -= g_Minigame.wallBallPitchPowerRemaining;
                if (wall->_24 <= 0) {
                    g_Minigame.wallBallPitchPowerRemaining = -wall->_24;
                    wall->_28 = 4;
                    g_Minigame.miniGameLatestPoints[g_Minigame.minigamePlayerSelectedOrder] += lbl_3_data_21654[wall->coinGenerationCategory + 7];
                    count = lbl_3_data_21648[wall->coinGenerationCategory];
                    for (j = 0; j < 100; j++) {
                        if (!g_Minigame.wallBall_coinsVisibleInd[j]) {
                            g_Minigame.wallBall_coinsVisibleFrameCounter[j] = 0;
                            g_Minigame.wallBall_coinsVisibleInd[j] = TRUE;
                            VEC_COPY(&g_Minigame.wallBall_coinCoordinates[j], &lbl_3_data_215E0[wall->wallPos]);
                            angle = MTXDegToRad(rand() % 180);
                            g_Minigame.wallBall_coinVelocity[j].x = lbl_3_data_21634[1] * COSF(angle);
                            g_Minigame.wallBall_coinVelocity[j].z = lbl_3_data_21634[1] * SINF(angle);
                            g_Minigame.wallBall_coinVelocity[j].y = lbl_3_data_21634[0];
                            if (--count == 0) {
                                break;
                            }
                        }
                    }
                    fn_3_6C854(g_Minigame.minigameControlStruct.characterIndex[g_Minigame.minigamePlayerSelectedOrder], 0);
                } else {
                    wall->_18 = 0.0f;
                    wall->_1C = lbl_3_data_21688[0];
                    wall->_20 = lbl_3_data_21688[1];
                    fn_3_90064(0x2E1);
                    fn_3_113EC0();
                }
                break;
            }
        }
    }
}

// .text:0x00113EC0 size:0x54 mapped:0x80752F54
void fn_3_113EC0(void) {
    g_Pitcher.ballVelocity.z = -g_Pitcher.ballVelocity.z;
    VEC_SCALE(&g_Pitcher.ballVelocity, &g_Pitcher.ballVelocity, lbl_3_data_21674[0]);
    g_Minigame.ballStoppedBreakingWallsInd = TRUE;
}

// .text:0x00113D20 size:0x1A0 mapped:0x80752DB4
void fn_3_113D20(void) {
    MaybeWallBallStruct* wall;
    int i;
    s8 flag = 0;
    s8 dir;
    f32 prev;
    f32 cur;

    for (i = 0; i < 7; i++) {
        wall = &g_Minigame.wallBallWalls[i];
        prev = wall->_18;
        if (prev == 0.0f && wall->_1C == 0.0f) {
            continue;
        }
        wall->_18 += wall->_1C * cos(prev);
        cur = wall->_18;
        if (cur >= 0.0f) {
            dir = -1;
        } else {
            dir = 1;
        }
        if (prev < cur) {
            if (prev < 0.0f && cur >= 0.0f) {
                flag = 1;
            }
        } else {
            if (prev > 0.0f && cur <= 0.0f) {
                flag = 1;
            }
        }
        if (flag) {
            wall->_1C *= lbl_3_data_21688[2];
            if (fabsf(wall->_1C) < wall->_20 * lbl_3_data_21688[2]) {
                wall->_18 = wall->_1C = wall->_20 = 0.0f;
            }
            flag = 0;
        }
        wall->_1C += dir * wall->_20;
    }
}

// .text:0x00113A48 size:0x2D8 mapped:0x80752ADC
void fn_3_113A48(void) {
    int i;
    int sum;
    s16 rem;

    if (g_Ball.pitchHangtimeCounter == 1) {
        g_Minigame.wallBallPitchPower = lbl_3_data_21654[3];
        if (g_Pitcher.ChargePitchType == 3) {
            g_Minigame.wallBallPitchPower = lbl_3_data_21654[2];
        } else if (g_Pitcher.ChargePitchType >= 2) {
            g_Minigame.wallBallPitchPower = LinearInterpolateToNewRange(g_Pitcher.pitchChargeUp, 0.0f, 1.0f, lbl_3_data_21654[0], lbl_3_data_21654[1]);
        }
        g_Minigame.wallBallPitchPowerRemaining = g_Minigame.wallBallPitchPower;
        i = sum = 0;
        do {
            sum += g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]]._24;
            if (g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].coinGenerationCategory == 2) {
                i++;
                break;
            }
            i++;
        } while (i < 7);
        if (g_Minigame.wallBallPitchPower >= sum) {
            if (i < 7) {
                if (g_Minigame.wallBallPitchPower <= sum + g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]]._24 - 1) {
                    g_Minigame.wallBall_hitNoteBlock = TRUE;
                }
            } else {
                g_Minigame.wallBall_hitNoteBlock = TRUE;
            }
        }
        if (g_Minigame.wallBall_hitNoteBlock != TRUE) {
            rem = g_Minigame.wallBallPitchPower;
            for (i = 0; i < 7; i++) {
                rem -= g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]]._24;
                if (rem < 0) {
                    break;
                }
            }
            if (--i >= 0 && g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].coinGenerationCategory == 1) {
                g_Minigame._1A8B = i;
                g_Minigame.wallBall_hitBowserWall = TRUE;
            }
        }
    }
}

// .text:0x00113950 size:0xF8 mapped:0x807529E4
void fn_3_113950(void) {
    int i;

    for (i = 0; i < 100; i++) {
        if (g_Minigame.wallBall_coinsVisibleInd[i]) {
            g_Minigame.wallBall_coinsVisibleFrameCounter[i]++;
            VEC_ADD(&g_Minigame.wallBall_coinCoordinates[i], &g_Minigame.wallBall_coinCoordinates[i], &g_Minigame.wallBall_coinVelocity[i]);
            g_Minigame.wallBall_coinVelocity[i].y -= lbl_3_data_21634[2];
            if (g_Minigame.wallBall_coinCoordinates[i].y < lbl_3_data_219B8[14]) {
                g_Minigame.wallBall_coinCoordinates[i].y = lbl_3_data_219B8[14];
                g_Minigame.wallBall_coinVelocity[i].y = -g_Minigame.wallBall_coinVelocity[i].y * lbl_3_data_21634[3];
                g_Minigame.wallBall_coinVelocity[i].x *= lbl_3_data_21634[4];
                g_Minigame.wallBall_coinVelocity[i].z *= lbl_3_data_21634[4];
            }
            if (g_Minigame.wallBall_coinsVisibleFrameCounter[i] > lbl_3_data_2167C[4]) {
                g_Minigame.wallBall_coinsVisibleInd[i] = 0;
            }
        }
    }
}

// .text:0x0011391C size:0x34 mapped:0x807529B0
void fn_3_11391C(void) {
    memset(g_Minigame._1D7C, 0, 0x78);
}

// .text:0x001136FC size:0x220 mapped:0x80752790
void fn_3_1136FC(void) {
    MiniGameStruct* mg = &g_Minigame;
    u8 strength;
    s8 i;
    s16 min;
    s16 max;
    s8 idx;
    s16 r;

    min = 0;
    max = 0x7FFF;
    idx = 0;
    strength = mg->minigameControlStruct.aIStrength[mg->minigamePlayerSelectedOrder];
    i = 0;
    do {
        min += g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]]._24;
        if (g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]].coinGenerationCategory == 2) {
            idx = i++;
            break;
        }
        i++;
    } while (i < 7);
    if (i < 7) {
        max = min + g_Minigame.wallBallWalls[g_Minigame.wallIndexTracker[i]]._24 - 1;
    }
    if (RandomInt_Game(100) < lbl_3_data_21694[strength][idx]) {
        r = RandomInt_Game_Range(lbl_3_data_216B0[strength][0], lbl_3_data_216B0[strength][1]);
        min += r;
        max += r;
    }
    if (min <= lbl_3_data_21654[2] && lbl_3_data_21654[2] <= max) {
        mg->_1DCE = 0;
    } else if (min <= lbl_3_data_21654[3] && lbl_3_data_21654[3] <= max) {
        mg->_1DCE = 3;
    } else if (max >= lbl_3_data_21654[0] && min <= lbl_3_data_21654[1]) {
        mg->_1DCE = 2;
        if (min < lbl_3_data_21654[0]) {
            min = lbl_3_data_21654[0];
        }
        if (max > lbl_3_data_21654[1]) {
            max = lbl_3_data_21654[1];
        }
        mg->_1DCC = RandomInt_Game_Range(min, max);
    } else {
        mg->_1DCE = 1;
    }
    if (mg->_1DCE == 0 && RandomInt_Game(100) < lbl_3_data_216B8[strength]) {
        mg->_1DCE = 1;
    }
}

// .text:0x001133C4 size:0x338 mapped:0x80752458
void fn_3_1133C4(void) {
    MiniGameStruct* mg = &g_Minigame;
    s8 i;
    s8 idx;
    s16 power;

    i = 0;
    do {
        g_Minigame._1DC4[i] = FALSE;
    } while (++i < 4);
    i = 0;
    do {
        if (g_Minigame.minigameControlStruct.characterIndex[i] >= 0 && g_Minigame.minigameControlStruct.characterIndex[i] < 4 &&
            i == g_Minigame.minigamePlayerSelectedOrder && g_Minigame.minigameControlStruct.battingHandedness[i]) {
            idx = g_Minigame.minigameControlStruct.characterIndex[i];
            g_Minigame._1DC4[idx] = TRUE;
            memset(&g_Minigame._1D7C[idx], 0, sizeof(InputStruct));
            switch (mg->_1DCF) {
            case 0:
                fn_3_1136FC();
                mg->_1DD0 = 60;
                mg->_1DCF = 1;
                break;
            case 1:
                if (--mg->_1DD0 > 0) {
                    break;
                }
                switch (mg->_1DCE) {
                case 0:
                    mg->_1DCF = 2;
                    break;
                case 1:
                    mg->_1DCF = 4;
                    break;
                case 2:
                    mg->_1DCF = 6;
                    break;
                case 3:
                default:
                    mg->_1DCF = 8;
                    break;
                }
                break;
            case 2:
                g_Minigame._1D7C[idx].newButtonInput |= INPUT_BUTTON_A;
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                mg->_1DCF = 3;
                break;
            case 3:
                if (g_Pitcher.windupCountdownUntilBallReleased < lbl_3_data_5F3C[2]) {
                    mg->_1DCF = 9;
                } else {
                    g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                }
                break;
            case 4:
                g_Minigame._1D7C[idx].newButtonInput |= INPUT_BUTTON_A;
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                mg->_1DCF = 5;
                break;
            case 5:
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                break;
            case 6:
                g_Minigame._1D7C[idx].newButtonInput |= INPUT_BUTTON_A;
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                mg->_1DCF = 7;
                break;
            case 7:
                if (!g_Pitcher.framesAHeldForChargePitches) {
                    power = LinearInterpolateToNewRange(1.0f - (f32)g_Pitcher.windupCountdownUntilBallReleased / (f32)g_Pitcher.pitchWindUpCountDown, 0.0f, 1.0f,
                                                        lbl_3_data_21654[0], lbl_3_data_21654[1]);
                    if (power >= mg->_1DCC) {
                        mg->_1DCF = 9;
                        break;
                    }
                }
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                break;
            case 8:
                g_Minigame._1D7C[idx].newButtonInput |= INPUT_BUTTON_A;
                g_Minigame._1D7C[idx].buttonInput |= INPUT_BUTTON_A;
                mg->_1DCF = 9;
                break;
            case 9:
                break;
            }
        }
    } while (++i < 4);
}
