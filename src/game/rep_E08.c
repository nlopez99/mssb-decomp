#include "game/rep_E08.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"

typedef struct UnkE08Fielder {
    /* 0x000 */ u8 _000[0xE8];
    /* 0x0E8 */ f32 _0E8;
    /* 0x0EC */ u8 _0EC[0x1C7 - 0xEC];
    /* 0x1C7 */ u8 _1C7;
    /* 0x1C8 */ u8 _1C8[0x1E5 - 0x1C8];
    /* 0x1E5 */ u8 _1E5;
    /* 0x1E6 */ u8 _1E6[0x248 - 0x1E6];
    /* 0x248 */ f32 _248;
    /* 0x24C */ s16 _24C;
    /* 0x24E */ u8 _24E[0x252 - 0x24E];
    /* 0x252 */ u8 _252;
    /* 0x253 */ u8 _253;
    /* 0x254 */ u8 _254[0x256 - 0x254];
    /* 0x256 */ u8 _256;
    /* 0x257 */ u8 _257[0x268 - 0x257];
} UnkE08Fielder; // size: 0x268

typedef struct UnkE08Anim {
    /* 0x00 */ u8 _00[0x38];
    /* 0x38 */ s16 _38;
    /* 0x3A */ s16 _3A;
    /* 0x3C */ u8 _3C[0x40 - 0x3C];
    /* 0x40 */ u8 _40;
    /* 0x41 */ u8 _41;
    /* 0x42 */ u8 _42[0x45 - 0x42];
    /* 0x45 */ u8 _45;
    /* 0x46 */ u8 _46[0x4A - 0x46];
    /* 0x4A */ s16 _4A;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x4E */ u8 _4E;
    /* 0x4F */ u8 _4F;
    /* 0x50 */ u8 _50[0x54 - 0x50];
} UnkE08Anim; // size: 0x54

typedef struct UnkE08Actor {
    /* 0x00 */ u8 _00[0x62];
    /* 0x62 */ s16 _62;
} UnkE08Actor;

typedef struct UnkE08Track {
    /* 0x00 */ s32 _00;
    /* 0x04 */ u8 _04[0xA - 0x4];
    /* 0x0A */ s16 _0A;
    /* 0x0C */ u8 _0C[0x54 - 0xC];
    /* 0x54 */ u8 _54;
    /* 0x55 */ u8 _55;
    /* 0x56 */ u8 _56;
    /* 0x58 */ f32 _58;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ u8 _60[0x90 - 0x60];
} UnkE08Track; // size: 0x90

typedef struct UnkE08Tracks {
    /* 0x00 */ u8 _00[0x38];
    /* 0x38 */ UnkE08Track _38[4];
} UnkE08Tracks;

extern struct {
    /* 0x0000 */ u8 _0000[0x60];
    /* 0x0060 */ UnkE08Tracks* _0060;
    /* 0x0064 */ u8 _0064[0x2C50 - 0x64];
    /* 0x2C50 */ UnkE08Actor* _2C50[10];
} lbl_8036E548;

extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ s16 _4;
    /* 0x6 */ u8 _6[0x8 - 0x6];
    /* 0x8 */ u8 _8;
    /* 0x9 */ u8 _9[0xB - 0x9];
    /* 0xB */ u8 _B;
} lbl_3_common_bss_32220;

extern struct {
    /* 0x00 */ Vec _00;
    /* 0x0C */ u8 _0C[0xE - 0xC];
    /* 0x0E */ u8 _0E;
} g_UnkThrowing_31ACC;

typedef struct UnkE08RunnerAnim {
    /* 0x00 */ u8 _00[0x1B];
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C[0x20 - 0x1C];
} UnkE08RunnerAnim; // size: 0x20

extern UnkE08RunnerAnim lbl_3_common_bss_321A0[4];

// .data outside this unit's range in splits.txt
extern s16 lbl_3_data_7870[][3];

extern UnkE08Fielder g_Fielders[9];
extern UnkE08Anim g_UnkAnimation_31EAC[9];

void QueueCharacterAnimation(int actor, int anim, u8, u8, s16, u8, int);
void AnimateCharacter(int actor, int anim, u8, u8, u8, s16, u8, int);

// .text:0x0006714C size:0x394 mapped:0x806A61E0
void fn_3_6714C(BOOL arg0) {
    return;
}

// .text:0x00067130 size:0x1C mapped:0x806A61C4
void fn_3_67130(void) {
    lbl_3_common_bss_32220._8 = 0;
    lbl_3_common_bss_32220._B = 0;
    lbl_3_common_bss_32220._4 = 0;
}

// .text:0x000668BC size:0x874 mapped:0x806A5950
void fn_3_668BC(void) {
    return;
}

// .text:0x000664FC size:0x3C0 mapped:0x806A5590
void fn_3_664FC(void) {
    return;
}

// .text:0x00066140 size:0x3BC mapped:0x806A51D4
void fn_3_66140(void) {
    return;
}

// .text:0x00065FE0 size:0x160 mapped:0x806A5074
void fn_3_65FE0(void) {
    BOOL flag;
    s32 actorIdx;
    s32 i;
    UnkE08Actor* actor;

    for (i = 0; i < 4; i++) {
        actorIdx = i;
        actor = lbl_8036E548._2C50[i];
        flag = FALSE;
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
            actorIdx = 9;
            actor = lbl_8036E548._2C50[9];
        }
        if (actor == NULL) {
            continue;
        }
        if (g_Minigame._19E8[i]._4 == 0 || g_Minigame._19E8[i]._4 == 2) {
            flag = TRUE;
        }
        if (g_Minigame._19E8[i]._2 < 0) {
            AnimateCharacter(actorIdx, 0x69, 1, 1, 1, 0, flag, 0);
        } else if (g_Minigame._19E8[i]._1 != 0) {
            if (actor->_62 == 0x69) {
                AnimateCharacter(actorIdx, 0x6A, 0, 1, 1, 0, flag, 0);
                QueueCharacterAnimation(actorIdx, 0x6B, 1, 1, 0, flag, -1);
            }
        } else {
            AnimateCharacter(actorIdx, 0x69, 1, 1, 1, 0, flag, 0);
        }
        if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
            break;
        }
    }
}

// .text:0x000657E4 size:0x7FC mapped:0x806A4878
void fn_3_657E4(void) {
    return;
}

// .text:0x00064BDC size:0xC08 mapped:0x806A3C70
void fn_3_64BDC(void) {
    return;
}

// .text:0x00063AF8 size:0x10E4 mapped:0x806A2B8C
void fn_3_63AF8(void) {
    return;
}

// .text:0x00063A38 size:0xC0 mapped:0x806A2ACC
void fn_3_63A38(void) {
    return;
}

// .text:0x00063874 size:0x1C4 mapped:0x806A2908
void fn_3_63874(s32 i) {
    InMemRunnerType* runner = &g_Runners[i];
    UnkE08RunnerAnim* anim = &lbl_3_common_bss_321A0[i];

    if (g_GameLogic.secondaryGameMode == SECONDARY_GAME_MODE_CHAINCHOMP_SPRINT && g_Minigame._1B15[i] == 1) {
        anim->_1B = 0x11;
    } else if (runner->batterStayInBattersBoxReason != 0) {
        anim->_1B = 1;
    } else if (runner->actionCode != 0) {
        anim->_1B = 8;
    } else if (runner->overRun1BStage >= 2) {
        if (runner->overRun1BStage == 2) {
            anim->_1B = 9;
        } else {
            anim->_1B = 0xA;
        }
    } else if (runner->overrunBaseStage >= 2) {
        if (runner->overrunBaseStage == 2) {
            anim->_1B = 0xB;
        } else {
            anim->_1B = 0xC;
        }
    } else if (runner->runningToDugoutInd == 1) {
        anim->_1B = 0xD;
    } else if (runner->runningToDugoutInd != 0) {
        anim->_1B = 0xE;
    } else if (runner->leadOffStatus == 1) {
        anim->_1B = 0xF;
    } else if (runner->leadOffStatus == 2) {
        anim->_1B = 0x10;
    } else if (runner->turnaroundCode != 0) {
        anim->_1B = 5;
    } else if (runner->runningDirectionCode == 1 || runner->runningDirectionCode == 3) {
        if (runner->turningAroundInd != 0 &&
            runner->framesSinceLastDirectionChange < lbl_3_data_7870[runner->charID][0]) {
            anim->_1B = 7;
        } else {
            anim->_1B = 2;
        }
    } else if (runner->baseStandingOn >= 0) {
        anim->_1B = 3;
    } else {
        anim->_1B = 4;
    }
}

// .text:0x000631AC size:0x6C8 mapped:0x806A2240
void fn_3_631AC(void) {
    return;
}

// .text:0x00062E70 size:0x33C mapped:0x806A1F04
void fn_3_62E70(void) {
    return;
}

// .text:0x00062E28 size:0x48 mapped:0x806A1EBC
void fn_3_62E28(void) {
    AnimateCharacter(1, 0x3D, 1, 1, 1, 0, g_Fielders[1]._1C7, 0);
}

// .text:0x00062E04 size:0x24 mapped:0x806A1E98
void fn_3_62E04(s32 i) {
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];

    anim->_3A = anim->_38;
    anim->_38 = 0;
}

// .text:0x00062D44 size:0xC0 mapped:0x806A1DD8
void fn_3_62D44(s32 i) {
    UnkE08Fielder* fielder = &g_Fielders[i];
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];

    anim->_41 = 0;
    if (fielder->_1E5 == 2) {
        anim->_41 = 1;
    } else if (fielder->_1E5 == 3) {
        anim->_41 = 2;
    }
    if (fielder->_256 != 0 && g_Ball.AtBat_ContactResult == 0 && fielder->_248 < fielder->_0E8 &&
        g_Ball.framesUntilBallHitsGround < 120 && g_Ball.maxYOfHit > 5.0f && g_FieldingLogic._144 != 0) {
        anim->_45 = 1;
    }
}

// .text:0x00062CA8 size:0x9C mapped:0x806A1D3C
void fn_3_62CA8(s32 i) {
    UnkE08Anim* anim = &g_UnkAnimation_31EAC[i];
    u8 kind;
    UnkE08Fielder* fielder = &g_Fielders[i];
    UnkE08Actor* actor = lbl_8036E548._2C50[i];

    if (anim->_4C == 0) {
        kind = fielder->_252;
        anim->_4C = kind;
        anim->_4A = fielder->_24C;
        if (kind == 1 || kind == 2) {
            anim->_4E = fielder->_253;
        }
        if (anim->_4C != 0) {
            anim->_4D = anim->_4C;
        }
    }
    if (actor != NULL && actor->_62 == 0x24) {
        anim->_4C = 0;
        anim->_4F = 0;
    }
}

// .text:0x00062B50 size:0x158 mapped:0x806A1BE4
void fn_3_62B50(void) {
    s16 holder = g_Ball.fielderWBallIndex;

    if (holder < 0) {
        g_UnkThrowing_31ACC._0E = 0;
        return;
    }
    if (g_FieldingLogic._0C4 < 0) {
        g_UnkThrowing_31ACC._0E = 0;
        return;
    }
    if (g_UnkThrowing_31ACC._0E != 0) {
        return;
    }
    g_FieldingLogic._10A = 0;
    g_UnkThrowing_31ACC._00.x = g_Ball.throwDestination.x;
    g_UnkThrowing_31ACC._00.y = g_Ball.throwDestination.y;
    g_UnkThrowing_31ACC._00.z = g_Ball.throwDestination.z;
    if (g_FieldingLogic._107 == 1 && holder == 0 && (g_FieldingLogic._0C4 == 1 || g_FieldingLogic._0C4 == 2 || g_FieldingLogic._0C4 == 3) &&
        g_Pitcher.pickOffLoc != 4 && g_Pitcher.pickOffLoc != -1) {
        g_UnkThrowing_31ACC._0E = 7;
    } else if (g_FieldingLogic.throwSpeedType == 8) {
        g_UnkThrowing_31ACC._0E = 3;
    } else if (g_FieldingLogic.throwSpeedType == 9) {
        g_UnkThrowing_31ACC._0E = 4;
    } else if (g_FieldingLogic.throwSpeedType == 10) {
        if (holder == 3) {
            g_UnkThrowing_31ACC._0E = 5;
        } else {
            g_UnkThrowing_31ACC._0E = 6;
        }
    } else if (g_FieldingLogic._109 != 0) {
        g_UnkThrowing_31ACC._0E = 2;
    } else {
        g_UnkThrowing_31ACC._0E = 1;
    }
}

// .text:0x00062904 size:0x24C mapped:0x806A1998
void fn_3_62904(void) {
    return;
}

// .text:0x00061B64 size:0xDA0 mapped:0x806A0BF8
void fn_3_61B64(void) {
    return;
}

// .text:0x00061544 size:0x620 mapped:0x806A05D8
void fn_3_61544(void) {
    return;
}

// .text:0x00061228 size:0x31C mapped:0x806A02BC
void fn_3_61228(void) {
    return;
}

// .text:0x00061148 size:0xE0 mapped:0x806A01DC
void fn_3_61148(void) {
    return;
}

// .text:0x00060E90 size:0x2B8 mapped:0x8069FF24
void fn_3_60E90(void) {
    return;
}

// .text:0x00060D80 size:0x110 mapped:0x8069FE14
BOOL fn_3_60D80(s32 i) {
    s16 state;
    s16 timer;
    UnkE08Anim* anim;
    int player;

    player = g_Minigame.minigameControlStruct._28[i - 2];
    anim = &g_UnkAnimation_31EAC[i];
    state = lbl_8036E548._2C50[player]->_62;
    timer = g_Minigame._1B34[player];

    if (timer < 0) {
        if (state == 0x1D || state == 0x1F) {
            AnimateCharacter(player, 0, 1, 3, 0, 0, anim->_40, -1);
        }
        return FALSE;
    }
    if (timer == 0) {
        if (g_Minigame._1C92[player] == 3) {
            AnimateCharacter(player, 0x1F, 0, 3, 0, 0, anim->_40, -1);
        } else {
            AnimateCharacter(player, 0x1D, 0, 3, 0, 0, anim->_40, -1);
        }
    }
    return TRUE;
}

// .text:0x00060A98 size:0x2E8 mapped:0x8069FB2C
void fn_3_60A98(void) {
    return;
}

// .text:0x00060804 size:0x294 mapped:0x8069F898
void fn_3_60804(void) {
    return;
}

// .text:0x00060768 size:0x9C mapped:0x8069F7FC
void fn_3_60768(void) {
    s32 i;
    UnkE08Track* track;

    for (i = 0; i < 4; i++) {
        track = &lbl_8036E548._0060->_38[i];
        track->_00 = 0;
        track->_0A = 0;
        track->_58 = 0.0f;
        track->_54 = 1;
        track->_55 = 0;
        track->_56 = 0;
        track->_5C = 0.0f;
    }
}
