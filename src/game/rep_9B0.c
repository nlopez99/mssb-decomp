#include "game/rep_9B0.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "static/UnknownHomes_Static.h"
#include "game/rep_720.h"

typedef struct {
    /* 0x000 */ u8 _000[0x257];
    /* 0x257 */ s8 _257;
    /* 0x258 */ u8 _258[0x279 - 0x258];
    /* 0x279 */ u8 _279;
} Unk9B0Model;

extern struct {
    /* 0x0000 */ u8 _0000[0x2C50];
    /* 0x2C50 */ Unk9B0Model* _2C50[13];
} lbl_8036E548;

typedef struct {
    /* 0x000 */ u8 _000[0x218];
    /* 0x218 */ u8 _218;
    /* 0x219 */ u8 _219[0x268 - 0x219];
} Unk9B0Fielder; // size: 0x268

extern Unk9B0Fielder g_Fielders[9];

typedef struct {
    /* 0x000 */ u8 _000[0x261];
    /* 0x261 */ s8 _261[0x27E - 0x261];
    /* 0x27E */ s8 _27E;
} Unk9B0Replay;

extern Unk9B0Replay* lbl_3_common_bss_1323C;

typedef struct {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
} Unk9B0Queue;

typedef struct {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ Unk9B0Queue* _0C;
    /* 0x10 */ u8 _10[0x18 - 0x10];
    /* 0x18 */ s16 _18;
    /* 0x1A */ u8 _1A[0x22 - 0x1A];
    /* 0x22 */ s16 _22;
} Unk9B0Task;

extern Unk9B0Task* lbl_803CC1B8;

extern void fn_800B0A14_removeQueue(Unk9B0Queue* queue);

// .text:0x00021C7C size:0x14 mapped:0x80660D10
void fn_3_21C7C(s32 arg0, s32 arg1) {
    lbl_3_common_bss_1323C->_261[arg0] = arg1;
}

// .text:0x00021BDC size:0xA0 mapped:0x80660C70
void fn_3_21BDC(void) {
    Unk9B0Task* task = lbl_803CC1B8;
    Unk9B0Queue* queue;

    switch (task->_22) {
    case 0:
        task->_22 = 1;
        task->_18 = 90;
        break;
    case 1:
        if (task->_18-- == 0) {
            task->_22 = 2;
        }
        break;
    case 2:
        queue = task->_0C;
        queue->_10 = 1;
        fn_800B0A14_removeQueue(queue);
        task->_22 = 0;
        break;
    }
}

// .text:0x00021AA8 size:0x134 mapped:0x80660B3C
void fn_3_21AA8(void) {
    Unk9B0Task* task = lbl_803CC1B8;
    InMemRunnerType* runner = g_Runners;
    Unk9B0Model* model = lbl_8036E548._2C50[9];
    Unk9B0Queue* queue;

    switch (task->_22) {
    case 0:
        if (runner->charID == 2 || runner->charID == 9) {
            task->_22 = 1;
        } else {
            task->_22 = 3;
        }
        break;
    case 1:
        if (task->_18-- == 0) {
            task->_22 = 2;
        }
        break;
    case 2:
        if ((model->_279 & 2) || (model->_279 & 1)) {
            fn_3_14E50();
        }
        if (lbl_3_common_bss_1323C->_27E == 0) {
            task->_22 = 3;
        }
        break;
    case 3:
        fn_3_14E1C();
        lbl_3_common_bss_1323C->_27E = 0;
        queue = lbl_803CC1B8->_0C;
        queue->_10 = 1;
        fn_800B0A14_removeQueue(queue);
        task->_22 = 0;
        break;
    }
}

// 87.36%: the target keeps &g_GameLogic and the captain index's offset (team * 4 + 0xF4)
// apart and loads with lwzx; this build folds them into one address before the loop.
// .text:0x000219CC size:0xDC mapped:0x80660A60
void fn_3_219CC(void) {
    int i;
    int n = 0;

    for (i = 0; i < 9; i++) {
        Unk9B0Fielder* f = &g_Fielders[i];
        if (g_GameLogic.Team_CaptainRosterLoc[g_d_GameSettings.humanTeamNumber] == lbl_8036E548._2C50[i]->_257) {
            f->_218 = 0;
        } else {
            f->_218 = ++n;
        }
    }
}
