#include "game/UnknownHomes_Game.h"
#include "game/m_sound.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/seq.h"

// The sound bank table: group data pointers, indexed by sound group
extern struct {
    /* 0x000 */ s32 _00;
    /* 0x004 */ void* groups[0xE3];
    /* 0x390 */ u8 _390;
    /* 0x391 */ u8 _391;
    /* 0x392 */ u8 _392[4];
    /* 0x396 */ u8 _396;
    /* 0x397 */ u8 _397[3];
    /* 0x39A */ u8 _39A;
    /* 0x39B */ u8 _39B;
} lbl_800EF808;

extern struct {
    /* 0x0000 */ SND_LISTENER listener;
    /* 0x0090 */ SND_EMITTER emitters[100];
    /* 0x1FD0 */ u8 _1FD0[100];
    /* 0x2034 */ u8 emitterActive[100];
} lbl_3_common_bss_32B20;

typedef struct Unk90754 {
    /* 0x00000 */ u8 _00000[0x11820];
    /* 0x11820 */ u8 _11820;
    /* 0x11821 */ u8 _11821;
} Unk90754;

// A queue of sound group loads, run by fn_3_8B094
typedef struct SoundLoadTask {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[2];
    /* 0x14 */ u8 head;
    /* 0x15 */ u8 tail;
    /* 0x16 */ struct {
        /* 0x0 */ s8 _0;
        /* 0x1 */ s8 state;
        /* 0x2 */ s8 _2;
    } entries[14];
} SoundLoadTask;

typedef struct SeqEntry {
    /* 0x0 */ u16 group;
    /* 0x2 */ u16 song;
    /* 0x4 */ u16 _4;
} SeqEntry;

extern BOOL fn_800214D0(void);
extern BOOL fn_80021518(s32 group, void* data);
extern void fn_800ACFB0(void* ptr);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 arg1);

extern unsigned long sndRemoveListener(SND_LISTENER* li);
extern unsigned long sndUpdateListener(SND_LISTENER* li, SND_FVECTOR* pos, SND_FVECTOR* dir, SND_FVECTOR* heading,
                                       SND_FVECTOR* up, u8 vol, SND_ROOM* room);
extern unsigned long sndAddListener(SND_LISTENER* li, SND_FVECTOR* pos, SND_FVECTOR* dir, SND_FVECTOR* heading,
                                    SND_FVECTOR* up, f32 front_sur, f32 back_sur, f32 soundSpeed, unsigned long flags,
                                    unsigned char vol, SND_ROOM* room);
extern s32 fn_800698F8(s32 charID);
extern bool32 sndSeqGetValid(s32 seqID);
extern void fn_800216F8(u8 group, int (*callback)(void));
extern int fn_8006285C(void);
extern void fn_800A86B4(s32 arg0);
extern void fn_800A88C0(void);
extern void fn_800A8B78(void);
extern unsigned long sndCheckEmitter(SND_EMITTER* em);
extern unsigned long sndRemoveEmitter(SND_EMITTER* em);
extern SoundLoadTask* lbl_803CC1B8;

// rep_1BC8.c declares these as void(u8) and BOOL(s16, s16), which the signed tests of their
// arguments without extension rule out, so the prototypes stay out of the header until it is fixed
void fn_3_90AB0(s32 charID);
BOOL fn_3_90B14(int first, int second);

// .data outside the unit's ranges
extern u16 lbl_3_data_8168[0x36];
extern u8 lbl_3_data_81D4[8];
extern u8 lbl_3_data_830C[0x16][2];
extern u8 lbl_3_data_8338[0x66][2];
extern u8 lbl_3_data_8530[2][0x180];
extern f32 lbl_3_data_88AC[3];
extern SeqEntry lbl_3_data_88E0[];
extern SND_FVECTOR lbl_3_data_8D70;

// .bss, in reverse address order
static s32 lbl_3_bss_1780[30];
static SND_VOICEID lbl_3_bss_177C;
static SND_VOICEID lbl_3_bss_1778;
static u32* lbl_3_bss_1774;
static u8 lbl_3_bss_1771;
static u8 lbl_3_bss_1770;
static f32 lbl_3_bss_176C;
static SoundLoadTask* lbl_3_bss_1768;
static f32 lbl_3_bss_1764;
static u8 lbl_3_bss_1761;
static u8 lbl_3_bss_1760;

// .text:0x000910AC size:0x48 mapped:0x806D0140
int fn_3_910AC(void) {
    fn_80021518(0x1C, lbl_800EF808.groups[1]);
    fn_80021518(0x1D, lbl_800EF808.groups[1]);
    return 0;
}

// .text:0x00091064 size:0x48 mapped:0x806D00F8
int fn_3_91064(void) {
    fn_80021518(0x1C, lbl_800EF808.groups[3]);
    fn_80021518(0x36, lbl_800EF808.groups[3]);
    return 0;
}

// .text:0x00090C14 size:0x9C mapped:0x806CFCA8
BOOL fn_3_90C14(int charID) {
    SoundLoadTask* task = lbl_803CC1B8;
    int group;

    if (lbl_3_common_bss_34C58._2C == 0) {
        lbl_3_common_bss_34C58._2D = charID;
        group = fn_800698F8(charID);
        task->_10 = 0;
        fn_800216F8(group + 5, fn_3_90F48);
        lbl_3_common_bss_34C58._2C++;
    } else if (task->_10 != 0) {
        lbl_3_common_bss_34C58._2C++;
        return TRUE;
    }
    return FALSE;
}

// .text:0x00090B14 size:0x100 mapped:0x806CFBA8
BOOL fn_3_90B14(int first, int second) {
    SoundLoadTask* task = lbl_803CC1B8;
    int group;

    if (lbl_3_common_bss_34C58._2C == 0) {
        lbl_3_common_bss_34C58._2C = 1;
    }
    if (lbl_3_common_bss_34C58._2C == 1 || lbl_3_common_bss_34C58._2C == 3) {
        if (lbl_3_common_bss_34C58._2C == 1) {
            lbl_3_common_bss_34C58._2D = first;
        } else {
            if (second < 0) {
                return TRUE;
            }
            lbl_3_common_bss_34C58._2D = second;
        }
        group = fn_800698F8(lbl_3_common_bss_34C58._2D);
        task->_10 = 0;
        fn_800216F8(group + 5, fn_3_90F48);
        lbl_3_common_bss_34C58._2C++;
    } else if (task->_10 != 0) {
        if (++lbl_3_common_bss_34C58._2C == 5) {
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x00090AB0 size:0x64 mapped:0x806CFB44
void fn_3_90AB0(s32 charID) {
    int idx;

    if (charID >= 0) {
        idx = fn_800698F8(charID) + 5;
        if (lbl_800EF808.groups[idx] != NULL) {
            fn_800214D0();
            fn_800ACFB0(lbl_800EF808.groups[idx]);
            lbl_800EF808.groups[idx] = NULL;
        }
    }
}

// .text:0x00090A18 size:0x98 mapped:0x806CFAAC
BOOL fn_3_90A18(void) {
    SoundLoadTask* task = lbl_803CC1B8;

    if (lbl_3_common_bss_34C58._2C == 0) {
        fn_800216F8(g_d_GameSettings.StadiumID + 0x27, fn_3_90798);
        task->_10 = 0;
        lbl_3_common_bss_34C58._2C++;
    } else if (task->_10 != 0) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000909B0 size:0x68 mapped:0x806CFA44
void fn_3_909B0(void) {
    int idx;

    fn_800214D0();
    idx = (g_d_GameSettings.StadiumID == STADIUM_ID_TOY_FIELD ? STADIUM_ID_TOY_FIELD : g_d_GameSettings.StadiumID) + 0x27;
    fn_800ACFB0(lbl_800EF808.groups[idx]);
    lbl_800EF808.groups[idx] = NULL;
}

// .text:0x00090928 size:0x88 mapped:0x806CF9BC
int fn_3_90928(void) {
    SoundLoadTask* task = lbl_803CC1B8;

    if (lbl_3_common_bss_34C58._2C == 0) {
        fn_800216F8(0x25, fn_8006285C);
        task->_10 = 0;
        lbl_3_common_bss_34C58._2C++;
    } else if (task->_10 != 0) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x000908E8 size:0x40 mapped:0x806CF97C
void fn_3_908E8(void) {
    fn_800214D0();
    fn_800ACFB0(lbl_800EF808.groups[0x25]);
    lbl_800EF808.groups[0x25] = NULL;
}

// .text:0x00090860 size:0x88 mapped:0x806CF8F4
BOOL fn_3_90860(void) {
    SoundLoadTask* task = lbl_803CC1B8;

    if (lbl_3_common_bss_34C58._2C == 0) {
        fn_800216F8(1, fn_3_910AC);
        task->_10 = 0;
        lbl_3_common_bss_34C58._2C++;
    } else if (task->_10 != 0) {
        return TRUE;
    }
    return FALSE;
}

// .text:0x0009081C size:0x44 mapped:0x806CF8B0
void fn_3_9081C(void) {
    fn_800214D0();
    fn_800214D0();
    fn_800ACFB0(lbl_800EF808.groups[1]);
    lbl_800EF808.groups[1] = NULL;
}

// .text:0x00090798 size:0x84 mapped:0x806CF82C
int fn_3_90798(void) {
    int idx = (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD ? STADIUM_ID_TOY_FIELD : g_d_GameSettings.StadiumID) + 0x27;

    fn_80021518(lbl_3_data_81D4[g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD ? STADIUM_ID_TOY_FIELD : g_d_GameSettings.StadiumID],
                lbl_800EF808.groups[idx]);
    return 0;
}

// .text:0x00090764 size:0x34 mapped:0x806CF7F8
int fn_3_90764(void) {
    fn_80021518(0x33, lbl_800EF808.groups[0x2E]);
    return 0;
}

// .text:0x00090754 size:0x10 mapped:0x806CF7E8
void fn_3_90754(Unk90754* p, u8 a, u8 b) {
    p->_11820 = a;
    p->_11821 = b;
}

// .text:0x000906FC size:0x58 mapped:0x806CF790
void fn_3_906FC(void) {
    u32* table = (u32*)lbl_3_common_bss_34C58._00;
    int i;

    for (i = 0; i < (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE ? 1 : 20); i++) {
        table[i] += (u32)table;
    }
    lbl_3_bss_1774 = table;
}

// .text:0x00090674 size:0x88 mapped:0x806CF708
void fn_3_90674(s32 song) {
    SeqEntry* entry = &lbl_3_data_88E0[song];

    lbl_3_common_bss_34C58._04 = sndSeqPlayEx(entry->group, entry->song, (void*)lbl_3_bss_1774[song], NULL, 0);
    sndSeqVolume(lbl_3_data_830C[song][0], 0, lbl_3_common_bss_34C58._04, 0);
}

// .text:0x00090434 size:0x138 mapped:0x806CF4C8
void fn_3_90434(void) {
    int i;

    fn_800A86B4(3);
    fn_800A88C0();
    fn_800A8B78();
    if (sndSeqGetValid(lbl_3_common_bss_34C58._04)) {
        sndSeqVolume(0, 0, lbl_3_common_bss_34C58._04, 1);
    }
    if (sndSeqGetValid(lbl_3_common_bss_34C58._08)) {
        sndSeqVolume(0, 0, lbl_3_common_bss_34C58._08, 1);
    }
    for (i = 0; i < 3; i++) {
        if (lbl_3_common_bss_34C58.voices[i] != SND_ID_ERROR) {
            sndFXKeyOff(lbl_3_common_bss_34C58.voices[i]);
            lbl_3_common_bss_34C58.voices[i] = SND_ID_ERROR;
        }
    }
    fn_3_8BDF4();
}

// .text:0x000903B8 size:0x7C mapped:0x806CF44C
void fn_3_903B8(void) {
    if (sndSeqGetValid(lbl_3_common_bss_34C58._04)) {
        sndSeqVolume(0, 0xA0, lbl_3_common_bss_34C58._04, 1);
    }
    if (sndSeqGetValid(lbl_3_common_bss_34C58._08)) {
        sndSeqVolume(0, 0xA0, lbl_3_common_bss_34C58._08, 1);
    }
}

// .text:0x00090328 size:0x90 mapped:0x806CF3BC
void fn_3_90328(s32 time) {
    if (time < 0) {
        time = 3000;
    }
    if (sndSeqGetValid(lbl_3_common_bss_34C58._04)) {
        sndSeqVolume(0, time, lbl_3_common_bss_34C58._04, 1);
    }
    if (sndSeqGetValid(lbl_3_common_bss_34C58._08)) {
        sndSeqVolume(0, time, lbl_3_common_bss_34C58._08, 1);
    }
}

// .text:0x000902FC size:0x2C mapped:0x806CF390
void fn_3_902FC(void) {
    sndVolume(0, 10, SND_ALL_VOLGROUPS);
}

// .text:0x00090294 size:0x68 mapped:0x806CF328
SND_VOICEID playSoundEffect(int sound) {
    SND_VOICEID vid = sndFXStartEx(sound, lbl_3_data_8338[sound - 0x151][0], 0x3F, 0);
    sndFXCtrl(vid, 0x5B, lbl_3_data_8338[sound - 0x151][1]);
    return vid;
}

// .text:0x00090220 size:0x74 mapped:0x806CF2B4
u32 fn_3_90220(s32 charID, s32 sound) {
    int fxid = lbl_3_data_8168[charID] + sound;
    int vol = lbl_3_data_8530[0][sound];
    int ctrl = lbl_3_data_8530[1][sound];
    SND_VOICEID vid = sndFXStartEx(fxid, vol, 0x3F, 0);
    sndFXCtrl(vid, 0x5B, ctrl);
    return vid;
}

// .text:0x00090150 size:0xD0 mapped:0x806CF1E4
void fn_3_90150(void) {
    return;
}

// .text:0x00090064 size:0xEC mapped:0x806CF0F8
SND_VOICEID fn_3_90064(int id) {
    return 0;
}

// .text:0x0008FF5C size:0x108 mapped:0x806CEFF0
SND_VOICEID fn_3_8FF5C(s32 sound, f32 x, f32 y, f32 z) {
    return 0;
}

// .text:0x0008FF18 size:0x44 mapped:0x806CEFAC
void fn_3_8FF18(void) {
    lbl_3_common_bss_34C58._0C = -1;
    lbl_3_common_bss_34C58._10 = -1;
    lbl_3_common_bss_34C58._14 = -1;
    lbl_3_common_bss_34C58._18 = -1;
    lbl_3_common_bss_34C58._1C = -1;
    lbl_3_common_bss_34C58._28 = 0;
    lbl_3_common_bss_34C58._04 = -1;
    lbl_3_common_bss_34C58._08 = -1;
    lbl_3_common_bss_34C58._2F = 0;
    lbl_3_common_bss_34C58._33 = 0;
    lbl_3_bss_1780[0] = -1;
}

// .text:0x0008FC80 size:0x298 mapped:0x806CED14
void fn_3_8FC80(void) {
    return;
}

// .text:0x0008FC0C size:0x74 mapped:0x806CECA0
void fn_3_8FC0C(void) {
    lbl_3_common_bss_34C58._26 = 0;
    if (lbl_3_common_bss_34C58._10 != SND_ID_ERROR) {
        sndFXKeyOff(lbl_3_common_bss_34C58._10);
        lbl_3_common_bss_34C58._10 = SND_ID_ERROR;
    }
    if (lbl_3_common_bss_34C58._14 != SND_ID_ERROR) {
        sndFXKeyOff(lbl_3_common_bss_34C58._14);
        lbl_3_common_bss_34C58._14 = SND_ID_ERROR;
    }
}

// .text:0x0008F21C size:0x9F0 mapped:0x806CE2B0
void fn_3_8F21C(void) {
    return;
}

// .text:0x0008F1C8 size:0x54 mapped:0x806CE25C
void fn_3_8F1C8(void) {
    lbl_3_common_bss_34C58._20 = -1;
    lbl_3_common_bss_34C58._22 = -1;
    lbl_3_common_bss_34C58._29 = 0;
    lbl_3_common_bss_34C58._2A = 0;
    fn_3_8B2E4();
}

// .text:0x0008DA80 size:0x1748 mapped:0x806CCB14
void fn_3_8DA80(void) {
    return;
}

// .text:0x0008D9C0 size:0xC0 mapped:0x806CCA54
void fn_3_8D9C0(void) {
    return;
}

// .text:0x0008CD74 size:0xC4C mapped:0x806CBE08
void fn_3_8CD74(void) {
    return;
}

// .text:0x0008C5C8 size:0x7AC mapped:0x806CB65C
void fn_3_8C5C8(void) {
    return;
}

// .text:0x0008C4F0 size:0xD8 mapped:0x806CB584
void fn_3_8C4F0(void) {
    return;
}

// .text:0x0008C2DC size:0x214 mapped:0x806CB370
void fn_3_8C2DC(void) {
    return;
}

// .text:0x0008C104 size:0x1D8 mapped:0x806CB198
void fn_3_8C104(s32 arg0) {
    return;
}

// .text:0x0008C07C size:0x88 mapped:0x806CB110
// 98.82%: the inlined fn_3_8B258 gets the queue pointer in r8 and its head in r7, where the
// target (and every other inlined copy) has the pointer in the lower register
void fn_3_8C07C(void) {
    fn_3_8B258(4, 0, 0);
}

// .text:0x0008BE8C size:0x1F0 mapped:0x806CAF20
void fn_3_8BE8C(void) {
    return;
}

// .text:0x0008BDF4 size:0x98 mapped:0x806CAE88
void fn_3_8BDF4(void) {
    fn_3_8B804();
    fn_3_8B7DC();
}

// .text:0x0008BBC4 size:0x230 mapped:0x806CAC58
s32 fn_3_8BBC4(u32 id, Vec* pos, Vec* dir, s32 arg3) {
    return 0;
}

// .text:0x0008BA60 size:0x164 mapped:0x806CAAF4
void fn_3_8BA60(s32 handle, Vec* pos, Vec* dir) {
    return;
}

// .text:0x0008B9BC size:0xA4 mapped:0x806CAA50
void fn_3_8B9BC(SND_FVECTOR* pos) {
    SND_FVECTOR heading;
    SND_FVECTOR dir;

    heading.x = 0.0f;
    heading.y = 0.0f;
    heading.z = -1.0f;
    dir.x = 0.0f;
    dir.y = 0.0f;
    dir.z = 0.0f;
    sndRemoveListener(&lbl_3_common_bss_32B20.listener);
    sndAddListener(&lbl_3_common_bss_32B20.listener, pos, &dir, &heading, &lbl_3_data_8D70, lbl_3_data_88AC[0],
                   lbl_3_data_88AC[0], lbl_3_data_88AC[0], SND_LISTENER_DOPPLERFX, 0x7F, NULL);
}

// .text:0x0008B964 size:0x58 mapped:0x806CA9F8
void fn_3_8B964(SND_FVECTOR* pos, SND_FVECTOR* dir, SND_FVECTOR* heading) {
    if (lbl_3_common_bss_32B20.listener.room != NULL) {
        sndUpdateListener(&lbl_3_common_bss_32B20.listener, pos, dir, heading, &lbl_3_data_8D70, 0x7F, NULL);
    }
}

// .text:0x0008B890 size:0xD4 mapped:0x806CA924
void fn_3_8B890(s32 handle) {
    return;
}

// .text:0x0008B804 size:0x8C mapped:0x806CA898
void fn_3_8B804(void) {
    int i;

    for (i = 0; i < 100; i++) {
        if (lbl_3_common_bss_32B20.emitterActive[i]) {
            if (sndCheckEmitter(&lbl_3_common_bss_32B20.emitters[i])) {
                sndRemoveEmitter(&lbl_3_common_bss_32B20.emitters[i]);
            }
            lbl_3_common_bss_32B20.emitterActive[i] = 0;
        }
    }
}

// .text:0x0008B7DC size:0x28 mapped:0x806CA870
void fn_3_8B7DC(void) {
    sndRemoveListener(&lbl_3_common_bss_32B20.listener);
}

// .text:0x0008B718 size:0xC4 mapped:0x806CA7AC
void fn_3_8B718(void) {
    return;
}

// .text:0x0008B2E4 size:0x34 mapped:0x806CA378
void fn_3_8B2E4(void) {
    lbl_3_bss_1768 = fn_800B0A5C_insertQueue(fn_3_8B094, 0);
}

// .text:0x0008B258 size:0x8C mapped:0x806CA2EC
BOOL fn_3_8B258(s32 state, s32 id, s32 arg) {
    u8 head;
    u8 next;

    if (lbl_3_bss_1768 == NULL || lbl_3_bss_1768->tail == (next = ((head = lbl_3_bss_1768->head) + 1) % 14)) {
        return FALSE;
    }
    lbl_3_bss_1768->head = next;
    lbl_3_bss_1768->entries[head]._0 = id;
    lbl_3_bss_1768->entries[head].state = state;
    lbl_3_bss_1768->entries[head]._2 = arg;
    return TRUE;
}
