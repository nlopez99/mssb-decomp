#include "game/rep_17E0.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"

// .data outside this unit's split
extern u8 lbl_3_data_4380[8];

// .text:0x0009CAF0 size:0x2A0 mapped:0x806DBB84
void fn_3_9CAF0(void) {
    if (g_Ball.deadBallReason == 1) {
        if (g_Ball.homeRunInd == 1) {
            if (g_Ball.homeRunClassification == 1) {
                lbl_3_common_bss_32A94._4 = 4;
            } else if (g_Ball.Hit_VerticalAngle < 0x100) {
                lbl_3_common_bss_32A94._4 = 8;
            } else {
                lbl_3_common_bss_32A94._4 = 12;
            }
        } else if (g_Ball.ballAngleFromHome < 0x400 - lbl_3_data_4380[g_d_GameSettings.StadiumID]) {
            if (g_Ball.homeRunClassification == 1) {
                lbl_3_common_bss_32A94._4 = 3;
            } else if (g_Ball.Hit_VerticalAngle < 0x100) {
                lbl_3_common_bss_32A94._4 = 7;
            } else {
                lbl_3_common_bss_32A94._4 = 11;
            }
        } else if (g_Ball.ballAngleFromHome > 0x400 + lbl_3_data_4380[g_d_GameSettings.StadiumID]) {
            if (g_Ball.homeRunClassification == 1) {
                lbl_3_common_bss_32A94._4 = 1;
            } else if (g_Ball.Hit_VerticalAngle < 0x100) {
                lbl_3_common_bss_32A94._4 = 5;
            } else {
                lbl_3_common_bss_32A94._4 = 9;
            }
        } else {
            if (g_Ball.homeRunClassification == 1) {
                lbl_3_common_bss_32A94._4 = 2;
            } else if (g_Ball.Hit_VerticalAngle < 0x100) {
                lbl_3_common_bss_32A94._4 = 6;
            } else {
                lbl_3_common_bss_32A94._4 = 10;
            }
        }
    } else if (g_Ball.AtBat_ContactResult == 3) {
        if (g_Runners[3].runnerOnFieldOrOutOrScored == 1 && g_Ball.timeSinceBallPickedUp < 60 &&
            g_Ball.framesSinceThrowStarted < 1 && g_Runners[3].tagUpInd == 0 &&
            g_Runners[3].fractionalBasesRan >= 3.15f) {
            lbl_3_common_bss_32A94._4 = 14;
        }
        if (g_Runners[3].runnerOnFieldOrOutOrScored == 3 && lbl_3_common_bss_32A94._4 == 14 &&
            g_Ball.framesSinceBallHitGroundOrWasCaught <= 240 && g_Strikes.storedOuts < 2) {
            lbl_3_common_bss_32A94._4 = 13;
            lbl_3_common_bss_32A94._0 = 17;
        }
        if (lbl_3_common_bss_32A94._4 == 14 &&
            (g_Runners[3].runningDirectionCode == 2 || g_Runners[3].runningDirectionCode == 3)) {
            lbl_3_common_bss_32A94._4 = 0;
        }
    }
}
