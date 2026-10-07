#include "game/rep_F80.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_1838.h"
#include "game/rep_1F58.h"
#include "game/rep_1E08.h"
#include "game/rep_2308.h"

typedef struct {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ f32 _54;
    /* 0x58 */ u8 _58;
    /* 0x59 */ u8 _59;
    /* 0x5A */ u8 _5A;
    /* 0x5B */ u8 _5B;
    /* 0x5C */ f32 _5C;
    /* 0x60 */ u8 _60[0x90 - 0x60];
} UnkF80Elem; // size: 0x90

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ UnkF80Elem _34[1];
} UnkF80Elems;

typedef struct {
    /* 0x000 */ u8 _000[0x34];
    /* 0x034 */ VecXYZ _034;
    /* 0x040 */ VecXYZ _040;
    /* 0x04C */ u8 _04C[0x252 - 0x4C];
    /* 0x252 */ s8 _252;
} UnkF80Actor;

typedef struct {
    /* 0x00 */ u8 _00[0x4];
    /* 0x04 */ VecXYZ _04;
    /* 0x10 */ VecXYZ _10;
    /* 0x1C */ u8 _1C[0x26 - 0x1C];
    /* 0x26 */ u8 _26;
    /* 0x27 */ u8 _27;
} UnkF80Marker; // size: 0x28

typedef struct {
    /* 0x000 */ u8 _000[0x2A8];
    /* 0x2A8 */ UnkF80Marker _2A8[4];
} UnkF80Markers;

extern struct {
    /* 0x0000 */ u8 _0000[0x64];
    /* 0x0064 */ UnkF80Elems* _0064;
    /* 0x0068 */ u8 _0068[0x2C50 - 0x68];
    /* 0x2C50 */ UnkF80Actor* _2C50[13];
    /* 0x2C84 */ u8 _2C84[0x2D90 - 0x2C84];
    /* 0x2D90 */ UnkF80Markers* _2D90;
} lbl_8036E548;

extern struct {
    /* 0x00 */ u8 _00[0xC8];
    /* 0xC8 */ u8 _C8;
    /* 0xC9 */ u8 _C9;
    /* 0xCA */ u8 _CA;
    /* 0xCB */ u8 _CB[0xD4 - 0xCB];
    /* 0xD4 */ u8 _D4;
} lbl_3_common_bss_32724;

extern struct {
    /* 0x0 */ u8 _0[0x2];
    /* 0x2 */ s16 _2;
    /* 0x4 */ u8 _4[0xA - 0x4];
    /* 0xA */ u8 _A;
} lbl_3_common_bss_32220;

extern struct {
    /* 0x0 */ f32 _0;
    /* 0x4 */ f32 _4;
} lbl_3_common_bss_3223C;

extern struct {
    /* 0x000 */ u8 _000[0x3AC];
    /* 0x3AC */ u32 _3AC;
} lbl_3_common_bss_35154;

extern void fn_3_C0770(void);
extern void fn_3_C07A0(void);
extern void fn_3_C07B0(void);
extern void fn_3_CB344(s32 idx, u8 starPitchType);
extern void fn_80011578(void);

// .text:0x0006AB58 size:0x368 mapped:0x806A9BEC
void fn_3_6AB58(void) {
    s32 type;

    lbl_3_common_bss_3223C._4 = game_atan2(g_Camera._284C.z - g_Camera._2840.z, g_Camera._284C.x - g_Camera._2840.x);
    fn_3_6AA98();
    fn_3_6A9B0();
    fn_3_6A83C();
    fn_3_6A414();
    fn_3_6A300();

    if (g_Ball.framesSinceHit == 0 && (lbl_3_common_bss_35154._3AC & 3) == 0) {
        if (g_Batter.captainStarSwingActivated != 0 || g_Batter.didNonCaptainStarSwingConnect) {
            type = 4;
        } else if (g_Batter.hitGeneralType == BAT_CONTACT_TYPE_BUNT) {
            type = 0;
        } else if (g_Batter.displayContactSprite != 0) {
            type = 3;
        } else if (g_Batter.contactType == HIT_CONTACT_TYPE_PERFECT) {
            type = 2;
        } else {
            type = 1;
        }

        if (g_Batter.batterHand == BATTING_HAND_RIGHT) {
            fn_3_BE174(type, g_Batter.hitContactPos.x, -g_Batter.hitContactPos.y, g_Batter.hitContactPos.z);
        } else {
            fn_3_BE174(type, -g_Batter.hitContactPos.x, -g_Batter.hitContactPos.y, g_Batter.hitContactPos.z);
        }
    }
}

// .text:0x0006AB30 size:0x28 mapped:0x806A9BC4
void fn_3_6AB30(void) {
    fn_3_BF1AC();
    fn_3_CABB4();
    fn_80011578();
}

// .text:0x0006AA98 size:0x98 mapped:0x806A9B2C
void fn_3_6AA98(void) {
    if (g_Batter.charID == CHAR_ID_DK || g_Batter.charID == CHAR_ID_DIDDY || g_Batter.charID == CHAR_ID_YOSHI) {
        return;
    }
    if (lbl_3_common_bss_32220._A == 0) {
        return;
    }
    if (lbl_3_common_bss_32220._A == 3 || lbl_3_common_bss_32220._A == 4) {
        fn_3_C07A0();
    } else if (lbl_3_common_bss_32220._A == 9) {
        fn_3_C0770();
    } else if (lbl_3_common_bss_32220._2 == 2 && lbl_3_common_bss_32220._A == 2) {
        fn_3_C07B0();
    }
}

// .text:0x0006A9B0 size:0xE8 mapped:0x806A9A44
void fn_3_6A9B0(void) {
    s32 idx;
    f32 chargeUp;
    f32 chargeDown;

    if (g_d_GameSettings.minigamesEnabled) {
        idx = g_Minigame.minigameControlStruct.characterIndex[g_Minigame.rosterID];
    } else {
        idx = 9;
    }

    if (g_Batter.chargeStatus == CHARGE_SWING_STAGE_CHARGEUP) {
        if (g_Batter.chargeFrames == 1) {
            fn_3_C1770(idx);
            lbl_3_common_bss_32724._C9 = 1;
        } else {
            chargeUp = 100.0f * g_Batter.chargeUp;
            chargeDown = 100.0f * g_Batter.chargeDown;
            fn_3_C1344(idx, chargeUp, chargeDown, chargeUp >= 100.0f);
        }
    } else if (lbl_3_common_bss_32724._C9 != 0) {
        fn_3_C11CC(idx, 1);
        lbl_3_common_bss_32724._C9 = 0;
    }
}

// .text:0x0006A83C size:0x174 mapped:0x806A98D0
// The statement count matters: written more compactly (fewer returns, no state/order
// locals), this is small enough for -inline auto to inline it into fn_3_6AB58.
void fn_3_6A83C(void) {
    VecXYZ pos;
    s32 idx = 0;
    s32 joint;
    u8 state;

    if (g_Pitcher.pitchTotalTimeCounter <= 0) {
        lbl_3_common_bss_32724._C8 = 0;
        return;
    }
    state = lbl_3_common_bss_32724._C8;
    if (state >= 2) {
        return;
    }

    if (g_d_GameSettings.minigamesEnabled) {
        s8 order = g_Minigame.minigamePlayerSelectedOrder;
        idx = g_Minigame.minigameControlStruct.characterIndex[order];
    }

    if (g_Pitcher.pitchTotalTimeCounter < 0) {
        return;
    }
    if (g_Pitcher.TypeOfPitch == 0 && g_Pitcher.ChargePitchType == 0) {
        return;
    }

    if (state == 0) {
        fn_3_CB344(idx, g_Pitcher.starPitchType);
        lbl_3_common_bss_32724._C8 = 1;
    }
    if (lbl_3_common_bss_32724._C8 != 1) {
        return;
    }

    if (g_Ball.pitchHangtimeCounter == 1 || g_GameLogic.gameStatus != GAME_STATUS_AT_BAT) {
        fn_3_CB234(idx, 1);
        lbl_3_common_bss_32724._C8 = 2;
        return;
    }

    joint = 0x1A;
    if (g_Pitcher.handedness != 0) {
        joint = 0x14;
    }
    getAnimRelatedCoordinates(idx, joint, &pos);
    fn_3_CB284(idx, g_Pitcher.windupCountdownUntilBallReleased, g_Pitcher.pitchChargeUpAnimationProportion);
}

// .text:0x0006A414 size:0x428 mapped:0x806A94A8
void fn_3_6A414(void) {
    if (g_Pitcher.pitchTotalTimeCounter <= 0) {
        if (lbl_3_common_bss_32724._CA != 0) {
            fn_3_BD4F0();
            lbl_3_common_bss_32724._CA = 0;
        }
        return;
    }

    if (g_Pitcher.starPitchType != 0 || g_Pitcher.nonCaptainStarPitchTriggeredType != 0) {
        fn_3_CB1B0(0, g_Pitcher.starPitchType, g_Pitcher.windupCountdownUntilBallReleased);
    }

    if (g_Ball.pitchHangtimeCounter == 1) {
        fn_3_BD6AC(0, g_Ball.AtBat_Contact_BallPos.x, -g_Ball.AtBat_Contact_BallPos.y,
                   g_Ball.AtBat_Contact_BallPos.z);
        switch (g_Pitcher.starPitchType) {
        case CAPTAIN_STAR_TYPE_MARIO:
        case CAPTAIN_STAR_TYPE_LUIGI:
            lbl_3_common_bss_32724._CA = 1;
            break;
        case CAPTAIN_STAR_TYPE_PEACH:
        case CAPTAIN_STAR_TYPE_DAISY:
            lbl_3_common_bss_32724._CA = 2;
            break;
        case CAPTAIN_STAR_TYPE_YOSHI:
        case CAPTAIN_STAR_TYPE_BIRDO:
            lbl_3_common_bss_32724._CA = 3;
            break;
        case CAPTAIN_STAR_TYPE_BOWSER:
        case CAPTAIN_STAR_TYPE_BOWSERJR:
            lbl_3_common_bss_32724._CA = 4;
            break;
        }
        return;
    }

    if (lbl_3_common_bss_32724._CA == 1) {
        fn_3_BD504(g_Ball.AtBat_Contact_BallPos.x, -g_Ball.AtBat_Contact_BallPos.y, g_Ball.AtBat_Contact_BallPos.z,
                   g_Ball.framesSinceHit >= 1);
        if ((g_Ball.framesSinceHit >= 0 || g_Ball.postPitchResultCounter >= 0 || g_GameLogic.gameStatus == 0) &&
            g_Ball.currentStarSwing != CAPTAIN_STAR_TYPE_MARIO && g_Ball.currentStarSwing != CAPTAIN_STAR_TYPE_LUIGI)
        {
            fn_3_BD4F0();
            lbl_3_common_bss_32724._CA = 0;
            return;
        }
    }

    if (lbl_3_common_bss_32724._CA == 3) {
        fn_3_BD504(g_Ball.AtBat_Contact_BallPos.x, -g_Ball.AtBat_Contact_BallPos.y, g_Ball.AtBat_Contact_BallPos.z,
                   g_Ball.framesSinceHit >= 1);
        if ((g_Ball.framesSinceHit >= 0 || g_Ball.postPitchResultCounter >= 0 || g_GameLogic.gameStatus == 0) &&
            g_Ball.currentStarSwing != CAPTAIN_STAR_TYPE_YOSHI && g_Ball.currentStarSwing != CAPTAIN_STAR_TYPE_BIRDO)
        {
            fn_3_BD4F0();
            lbl_3_common_bss_32724._CA = 0;
            return;
        }
    }

    if (g_Ball.framesSinceHit == 1) {
        switch (g_Ball.currentStarSwing) {
        case CAPTAIN_STAR_TYPE_MARIO:
        case CAPTAIN_STAR_TYPE_LUIGI:
            fn_3_BD6AC(1, g_Ball.AtBat_Contact_BallPos.x, -g_Ball.AtBat_Contact_BallPos.y,
                       g_Ball.AtBat_Contact_BallPos.z);
            lbl_3_common_bss_32724._CA = 1;
            break;
        case CAPTAIN_STAR_TYPE_PEACH:
        case CAPTAIN_STAR_TYPE_DAISY:
            fn_3_BD6AC(1, g_Ball.AtBat_Contact_BallPos.x, -g_Ball.AtBat_Contact_BallPos.y,
                       g_Ball.AtBat_Contact_BallPos.z);
            break;
        case CAPTAIN_STAR_TYPE_YOSHI:
        case CAPTAIN_STAR_TYPE_BIRDO:
            fn_3_BD6AC(1, g_Ball.AtBat_Contact_BallPos.x, -g_Ball.AtBat_Contact_BallPos.y,
                       g_Ball.AtBat_Contact_BallPos.z);
            lbl_3_common_bss_32724._CA = 3;
            break;
        case CAPTAIN_STAR_TYPE_BOWSER:
        case CAPTAIN_STAR_TYPE_BOWSERJR:
            fn_3_BD6AC(1, g_Ball.AtBat_Contact_BallPos.x, -g_Ball.AtBat_Contact_BallPos.y,
                       g_Ball.AtBat_Contact_BallPos.z);
            lbl_3_common_bss_32724._CA = 4;
            break;
        case CAPTAIN_STAR_TYPE_WARIO:
        case CAPTAIN_STAR_TYPE_WALUIGI:
            fn_3_BD6AC(1, g_Ball.AtBat_Contact_BallPos.x, -g_Ball.AtBat_Contact_BallPos.y,
                       g_Ball.AtBat_Contact_BallPos.z);
            lbl_3_common_bss_32724._CA = 5;
            break;
        }
    }

    if (lbl_3_common_bss_32724._CA != 0) {
        fn_3_BD504(g_Ball.AtBat_Contact_BallPos.x, -g_Ball.AtBat_Contact_BallPos.y, g_Ball.AtBat_Contact_BallPos.z,
                   g_Ball.framesSinceHit >= 1);
        if ((g_Ball.framesSinceHit >= 0 || g_Ball.postPitchResultCounter >= 0 || g_GameLogic.gameStatus == 0) &&
            g_Ball.currentStarSwing == CAPTAIN_STAR_TYPE_NONE)
        {
            fn_3_BD4F0();
            lbl_3_common_bss_32724._CA = 0;
        }
    }
}

// .text:0x0006A400 size:0x14 mapped:0x806A9494
void fn_3_6A400(void) {
    lbl_3_common_bss_32724._D4 = 0;
}

// .text:0x0006A300 size:0x100 mapped:0x806A9394
void fn_3_6A300(void) {
    UnkF80Actor* actor;
    UnkF80Marker* marker;

    if (lbl_3_common_bss_32724._D4 == 0) {
        return;
    }

    actor = lbl_8036E548._2C50[9];
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        actor = lbl_8036E548._2C50[g_Minigame.rosterID];
    }

    if (actor->_252 == 0x30) {
        marker = &lbl_8036E548._2D90->_2A8[0];
    } else if (actor->_252 == 0x31) {
        marker = &lbl_8036E548._2D90->_2A8[1];
    } else if (actor->_252 == 0x32) {
        marker = &lbl_8036E548._2D90->_2A8[2];
    } else {
        marker = &lbl_8036E548._2D90->_2A8[3];
    }

    marker->_26 = 1;
    marker->_04.x = actor->_034.x;
    marker->_04.y = -actor->_034.y;
    marker->_04.z = actor->_034.z;
    marker->_10.x = actor->_040.x;
    marker->_10.y = -actor->_040.y;
    marker->_10.z = actor->_040.z;
}

// .text:0x0006A2A4 size:0x5C mapped:0x806A9338
void fn_3_6A2A4(s8 arg0) {
    UnkF80Elem* elem = &lbl_8036E548._0064->_34[arg0 - 0x1F];

    lbl_3_common_bss_32724._D4 = 1;
    elem->_5B = 2;
    elem->_5C = 0.0f;
    elem->_59 = 1;
    elem->_54 = 1.0f;
    elem->_5A = 1;
}
