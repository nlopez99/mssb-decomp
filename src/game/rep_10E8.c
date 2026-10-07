#include "game/rep_10E8.h"
// Must precede header_rep_data.h: its extern inline dolsqrtf2 puts weak constants first
#include "game/UnknownHomes_Game.h"
#include "header_rep_data.h"
#include "game/rep_1838.h"
#include "static/UnknownHomes_Static.h"

// .text:0x0006D304 size:0x19C mapped:0x806AC398
// Differs only at the loop top: the target holds the 0 for _0E in r3 and loads _00 into r0
// before the stb; this build uses r0 for the 0 and loads _02 first.
void fn_3_6D304(void) {
    int i;
    u16 buttons;

    for (i = 0; i < 4; i++) {
        g_Controls[i]._0E = 0;
        buttons = g_Controls[i].buttonInput;
        g_Controls[i].buttonInput = lbl_803C77B8[i]._00;
        g_Controls[i].newButtonInput = lbl_803C77B8[i]._02;
        g_Controls[i]._08 = lbl_803C77B8[i]._04;
        g_Controls[i].right_left = lbl_803C77B8[i]._10;
        g_Controls[i].up_down = lbl_803C77B8[i]._11;
        g_Controls[i].leftTriggerDistance = lbl_803C77B8[i]._14;
        g_Controls[i].rightTriggerDistance = lbl_803C77B8[i]._15;
        if ((g_Controls[i].newButtonInput & INPUT_TRIGGER_L) && (buttons & INPUT_TRIGGER_L)) {
            g_Controls[i].newButtonInput &= 0xFFBF;
        }
        if (g_Controls[i].leftTriggerDistance >= 120.0f) {
            if (!(buttons & INPUT_TRIGGER_L)) {
                g_Controls[i].newButtonInput |= INPUT_TRIGGER_L;
            }
            g_Controls[i].buttonInput |= INPUT_TRIGGER_L;
        }
        if ((g_Controls[i].newButtonInput & INPUT_TRIGGER_R) && (buttons & INPUT_TRIGGER_R)) {
            g_Controls[i].newButtonInput &= 0xFFDF;
        }
        if (g_Controls[i].rightTriggerDistance >= 120.0f) {
            if (!(buttons & INPUT_TRIGGER_R)) {
                g_Controls[i].newButtonInput |= INPUT_TRIGGER_R;
            }
            g_Controls[i].buttonInput |= INPUT_TRIGGER_R;
        }
        fn_3_6CD88(i);
    }
}

// .text:0x0006CD88 size:0x57C mapped:0x806ABE1C
void fn_3_6CD88(int i) {
    s16 angle = -1;
    int magnitude;
    int a;
    f32 x;
    f32 y;
    f32 m;
    f32 scale;

    x = g_Controls[i].right_left;
    y = g_Controls[i].up_down;
    m = dolsqrtf2(SQ(x) + SQ(y)) - 16.0f;
    if (m <= 0.0f) {
        if ((g_Controls[i].buttonInput & INPUT_BUTTON_UP) && (g_Controls[i].buttonInput & INPUT_BUTTON_RIGHT)) {
            g_Controls[i].controlStickAngle = 0x200;
            g_Controls[i].controlStickMagnitude = 0x40;
        } else if ((g_Controls[i].buttonInput & INPUT_BUTTON_UP) && (g_Controls[i].buttonInput & INPUT_BUTTON_LEFT)) {
            g_Controls[i].controlStickAngle = 0x600;
            g_Controls[i].controlStickMagnitude = 0x40;
        } else if ((g_Controls[i].buttonInput & INPUT_BUTTON_DOWN) && (g_Controls[i].buttonInput & INPUT_BUTTON_RIGHT)) {
            g_Controls[i].controlStickAngle = 0xE00;
            g_Controls[i].controlStickMagnitude = 0x40;
        } else if ((g_Controls[i].buttonInput & INPUT_BUTTON_DOWN) && (g_Controls[i].buttonInput & INPUT_BUTTON_LEFT)) {
            g_Controls[i].controlStickAngle = 0xA00;
            g_Controls[i].controlStickMagnitude = 0x40;
        } else if (g_Controls[i].buttonInput & INPUT_BUTTON_UP) {
            g_Controls[i].controlStickAngle = 0x400;
            g_Controls[i].controlStickMagnitude = 0x40;
        } else if (g_Controls[i].buttonInput & INPUT_BUTTON_RIGHT) {
            g_Controls[i].controlStickAngle = 0;
            g_Controls[i].controlStickMagnitude = 0x40;
        } else if (g_Controls[i].buttonInput & INPUT_BUTTON_DOWN) {
            g_Controls[i].controlStickAngle = 0xC00;
            g_Controls[i].controlStickMagnitude = 0x40;
        } else if (g_Controls[i].buttonInput & INPUT_BUTTON_LEFT) {
            g_Controls[i].controlStickAngle = 0x800;
            g_Controls[i].controlStickMagnitude = 0x40;
        } else {
            g_Controls[i].controlStickAngle = -1;
            g_Controls[i].controlStickMagnitude = 0;
        }
    } else {
        if (m > 56.0f) {
            m = 56.0f;
        }
        magnitude = (s16)(64.0f * m / 56.0f);
        if (magnitude != 0) {
            angle = radToShortAngle(atan2(y, x));
            a = angle % 0x400;
            if (a > 0x200) {
                a = 0x400 - a;
            }
            scale = scaleValue(a / 512.0f, 0.27208483f);
            x += x * scale;
            y += y * scale;
            g_Controls[i].right_left = x;
            g_Controls[i].up_down = y;
            m = dolsqrtf2(SQ(x) + SQ(y)) - 16.0f;
            if (m > 56.0f) {
                m = 56.0f;
            }
            magnitude = (s16)(64.0f * m / 56.0f);
        }
        g_Controls[i].controlStickAngle = angle;
        g_Controls[i].controlStickMagnitude = magnitude;
    }
}
