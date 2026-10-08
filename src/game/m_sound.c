#include "game/UnknownHomes_Game.h"
#include "game/m_sound.h"
#include "header_rep_data.h"
#include "static/UnknownHomes_Static.h"
#include "musyx/seq.h"
#include "game/rep_720.h"
#include "Dolphin/os.h"
#include "game/rep_1CB8.h"

// The sound bank table: group data pointers, indexed by sound group
extern struct {
    /* 0x000 */ s32 _00;
    /* 0x004 */ void* groups[0xE3];
    /* 0x390 */ u8 _390;
    /* 0x391 */ u8 _391;
    /* 0x392 */ u8 _392[4];
    /* 0x396 */ u8 _396;
    /* 0x397 */ u8 _397;
    /* 0x398 */ u8 _398;
    /* 0x399 */ u8 _399;
    /* 0x39A */ u8 _39A;
    /* 0x39B */ u8 _39B;
} lbl_800EF808;

extern struct {
    /* 0x0000 */ SND_LISTENER listener;
    /* 0x0090 */ SND_EMITTER emitters[100];
    /* 0x1FD0 */ u8 emitterType[100];
    /* 0x2034 */ u8 emitterActive[100];
    /* 0x2098 */ u8 _2098[100];
    /* 0x20FC */ u8 _20FC;
    /* 0x20FD */ u8 _20FD;
} lbl_3_common_bss_32B20;

typedef struct Unk90754 {
    /* 0x00000 */ u8 _00000[0x11820];
    /* 0x11820 */ u8 _11820;
    /* 0x11821 */ u8 _11821;
} Unk90754;

typedef struct SoundLoad {
    /* 0x0 */ s8 id;
    /* 0x1 */ s8 state;
    /* 0x2 */ s8 arg;
} SoundLoad;

// A queue of sound group loads, run by fn_3_8B094
typedef struct SoundLoadTask {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[2];
    /* 0x14 */ u8 head;
    /* 0x15 */ u8 tail;
    /* 0x16 */ s8 queue[14 * 3];
} SoundLoadTask;

// Emitter parameters in hundred-thousandths, indexed by emitter type
typedef struct EmitterParams {
    /* 0x00 */ s32 pos[3];
    /* 0x0C */ s32 maxDis;
    /* 0x10 */ s32 comp;
    /* 0x14 */ s32 maxVol;
    /* 0x18 */ s32 minVol;
    /* 0x1C */ u32 flags[7];
    /* 0x38 */ s32 _38;
} EmitterParams;

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
extern void fn_800A8B78(void);
extern unsigned long sndCheckEmitter(SND_EMITTER* em);
extern unsigned long sndRemoveEmitter(SND_EMITTER* em);
extern SoundLoadTask* lbl_803CC1B8;
extern struct {
    /* 0x00 */ s16 _0;
    /* 0x02 */ s16 _2;
} g_RunningLogic;
typedef struct UnkPlayer8CD74 {
    /* 0x000 */ u8 _000[0x62];
    /* 0x062 */ s16 _62;
    /* 0x064 */ u8 _064[6];
    /* 0x06A */ s16 _6A;
    /* 0x06C */ u8 _06C[0x27C - 0x6C];
} UnkPlayer8CD74;
extern struct {
    /* 0x0000 */ u8 _0000[0xC04];
    /* 0x0C04 */ UnkPlayer8CD74 _C04[13];
    /* 0x2C50 */ u8 _2C50[0x24];
    /* 0x2C74 */ UnkPlayer8CD74* _2C74;
    /* 0x2C78 */ u8 _2C78[0x307D - 0x2C78];
    /* 0x307D */ u8 _307D;
} lbl_8036E548;
extern struct {
    /* 0x00 */ u8 _00[0xC2];
    /* 0xC2 */ u8 _C2;
} g_Scores;
extern unsigned long sndAddEmitter(SND_EMITTER* em_buffer, SND_FVECTOR* pos, SND_FVECTOR* dir, f32 maxDis, f32 comp,
                                   unsigned long flags, unsigned short fxid, unsigned char maxVol, unsigned char minVol,
                                   SND_ROOM* room);
extern unsigned long sndUpdateEmitter(SND_EMITTER* em, SND_FVECTOR* pos, SND_FVECTOR* dir, u8 maxVol, SND_ROOM* room);
extern camera_803c639c_s* fn_80052734(s32 idx);
extern u32 fn_800A8864(void);
extern void fn_800A8878(u8 a, u8 b);
extern u8 lbl_800E8558[][6];
extern u8 lbl_800E88A4[][2];
extern void* fn_800A88C0(void);
extern u32 fn_800A88C8(void);
extern u32 fn_800A88D0(void);
extern void fn_800A8AB0(s32 arg0);
extern void fn_800A8AB8(s32 arg0);
extern BOOL fn_800A8518(s32 arg0);
extern void LoadFile(char* name, void* dest, s32 arg2, s32 arg3, s32 arg4);
extern u8 lbl_8034E478[16][0x50];
extern char lbl_800E87B4[15][16];

// rep_1BC8.c declares these as void(u8) and BOOL(s16, s16), which the signed tests of their
// arguments without extension rule out, so the prototypes stay out of the header until it is fixed
void fn_3_90AB0(s32 charID);
BOOL fn_3_90B14(int first, int second);

// .data
static u8 lbl_3_data_8148[0x20] = {
    0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C,
    0x0B, 0x0A, 0x23, 0x07, 0x09, 0x21, 0x22, 0x08, 0x30, 0x2E, 0x27, 0x2F, 0x32, 0x25, 0x24, 0x26,
};
static u16 lbl_3_data_8168[0x36] = {
    0x144, 0x137, 0x12A, 0x11D, 0x110, 0x103, 0x0F6, 0x0E9, 0x0DC,
    0x0CF, 0x0C2, 0x0B5, 0x0A8, 0x09B, 0x08E, 0x081, 0x074, 0x067,
    0x201, 0x040, 0x05A, 0x1E7, 0x1E7, 0x1E7, 0x1F4, 0x1F4, 0x1F4,
    0x04D, 0x277, 0x09B, 0x09B, 0x09B, 0x09B, 0x25D, 0x25D, 0x25D,
    0x25D, 0x235, 0x26A, 0x2C9, 0x21B, 0x20E, 0x0A8, 0x05A, 0x074,
    0x074, 0x074, 0x074, 0x228, 0x228, 0x228, 0x228, 0x04D, 0x04D,
};
u8 lbl_3_data_81D4[8] = {
    0x2A, 0x2B, 0x2C, 0x34, 0x02, 0x01, 0x06, 0x00,
};
u16 lbl_3_data_81DC[0x10] = {
    0x248, 0x24A, 0x252, 0x30F, 0x010, 0x001, 0x022, 0x000,
    0x249, 0x251, 0x258, 0x00F, 0x017, 0x00F, 0x03F, 0x000,
};
u16 lbl_3_data_81FC[0x39] = {
    0x2D6, 0x2D7, 0x2D8, 0x2D9, 0x2E1, 0x2E2, 0x2E3, 0x2E4,
    0x2E5, 0x2E6, 0x2DD, 0x2DE, 0x2DF, 0x2E0, 0x2DA, 0x2DB,
    0x2DC, 0x2E7, 0x2E8, 0x2E9, 0x2EA, 0x2EB, 0x2EC, 0x2ED,
    0x2EE, 0x2EF, 0x2F0, 0x2F1, 0x2F2, 0x2F3, 0x2F4, 0x2F5,
    0x2F6, 0x2F7, 0x2F8, 0x2F9, 0x2FA, 0x2FB, 0x2FC, 0x2FD,
    0x2FE, 0x2FF, 0x300, 0x301, 0x302, 0x303, 0x304, 0x305,
    0x306, 0x307, 0x308, 0x309, 0x30A, 0x30B, 0x30C, 0x30D,
    0x30E,
};
static u8 lbl_3_data_8270[7] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
};
static u8 lbl_3_data_8278[12] = {
    0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78,
};
static u8 lbl_3_data_8284[0x66] = {
    0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
    0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
    0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
    0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
    0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
    0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
};
u8 lbl_3_data_82EC[0x20] = {
    0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
static u8 lbl_3_data_830C[0x16][2] = {
    { 0x4B, 0x28 }, { 0x4B, 0x28 }, { 0x55, 0x28 }, { 0x55, 0x28 }, { 0x55, 0x28 }, { 0x55, 0x28 }, { 0x55, 0x28 }, { 0x55, 0x28 },
    { 0x55, 0x28 }, { 0x5A, 0x28 }, { 0x55, 0x28 }, { 0x55, 0x28 }, { 0x55, 0x28 }, { 0x55, 0x28 }, { 0x55, 0x28 }, { 0x55, 0x28 },
    { 0x5A, 0x28 }, { 0x5F, 0x28 }, { 0x69, 0x28 }, { 0x00, 0x00 }, { 0x55, 0x28 }, { 0x00, 0x00 },
};
static u8 lbl_3_data_8338[0x66][2] = {
    { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x46, 0x00 }, { 0x4B, 0x00 }, { 0x55, 0x00 }, { 0x5A, 0x00 }, { 0x5A, 0x00 },
    { 0x64, 0x00 }, { 0x7F, 0x00 }, { 0x64, 0x00 }, { 0x78, 0x00 }, { 0x64, 0x00 }, { 0x7F, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 },
    { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 },
    { 0x7F, 0x00 }, { 0x64, 0x00 }, { 0x6E, 0x00 }, { 0x7F, 0x00 }, { 0x75, 0x00 }, { 0x75, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 },
    { 0x57, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x57, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x7F, 0x00 },
    { 0x7F, 0x00 }, { 0x75, 0x00 }, { 0x54, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x50, 0x00 }, { 0x5A, 0x00 }, { 0x7F, 0x00 },
    { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 },
    { 0x75, 0x00 }, { 0x6B, 0x00 }, { 0x64, 0x00 }, { 0x73, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 },
    { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x6B, 0x00 }, { 0x55, 0x00 }, { 0x6B, 0x00 },
    { 0x6B, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x75, 0x00 }, { 0x66, 0x00 }, { 0x75, 0x00 }, { 0x7F, 0x00 }, { 0x55, 0x00 },
    { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x6E, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 },
    { 0x73, 0x00 }, { 0x6E, 0x00 }, { 0x5A, 0x00 }, { 0x6E, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x6B, 0x00 }, { 0x7F, 0x00 },
    { 0x75, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x73, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 },
};
u8 lbl_3_data_8404[6][15][2] = {
    { { 0x3C, 0x00 }, { 0x5A, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 } },
    { { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x69, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 } },
    { { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 } },
    { { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x64, 0x00 }, { 0x7F, 0x00 }, { 0x41, 0x00 }, { 0x46, 0x00 }, { 0x46, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 } },
    { { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x32, 0x00 }, { 0x4D, 0x00 }, { 0x4D, 0x00 }, { 0x57, 0x00 }, { 0x57, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 }, { 0x00, 0x00 } },
    { { 0x7F, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x3C, 0x00 }, { 0x3C, 0x00 }, { 0x69, 0x00 }, { 0x7F, 0x00 }, { 0x6E, 0x00 }, { 0x7F, 0x00 }, { 0x6E, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 } },
};
u8 lbl_3_data_84B8[30][2] = {
    { 0x7F, 0x00 }, { 0x6B, 0x00 }, { 0x64, 0x00 }, { 0x5F, 0x00 }, { 0x75, 0x00 }, { 0x70, 0x00 }, { 0x6B, 0x00 }, { 0x7F, 0x00 },
    { 0x6B, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x4B, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 }, { 0x7F, 0x00 },
    { 0x64, 0x00 }, { 0x64, 0x00 }, { 0x69, 0x00 }, { 0x75, 0x00 }, { 0x69, 0x00 }, { 0x5F, 0x00 }, { 0x5F, 0x00 }, { 0x69, 0x00 },
    { 0x64, 0x00 }, { 0x6E, 0x00 }, { 0x78, 0x00 }, { 0x6E, 0x00 }, { 0x6E, 0x00 }, { 0x7F, 0x00 },
};
u8 lbl_3_data_84F4[0x3C] = {
    0x6B, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x4D, 0x4D, 0x7F, 0x61, 0x6B, 0x61, 0x61, 0x7F, 0x6B,
    0x5F, 0x69, 0x43, 0x37, 0x7F, 0x7F, 0x7F, 0x69, 0x7F, 0x61, 0x75, 0x75, 0x64, 0x5F, 0x7F, 0x64,
    0x64, 0x7F, 0x69, 0x5A, 0x64, 0x6B, 0x7F, 0x7F, 0x5A, 0x7F, 0x7F, 0x75, 0x7F, 0x7F, 0x73, 0x64,
    0x73, 0x6E, 0x6E, 0x7F, 0x73, 0x73, 0x7F, 0x7F, 0x78, 0x00, 0x00, 0x00,
};
static u8 lbl_3_data_8530[2][0x180] = {
    {
        0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
        0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
    },
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};
static f32 lbl_3_data_8830 = 0.6f;
f32 lbl_3_data_8834[6][4] = {
    { 50.0f, 0.0f, 127.0f, 10.0f },
    { 50.0f, 0.0f, 127.0f, 10.0f },
    { 50.0f, 0.0f, 127.0f, 10.0f },
    { 50.0f, 0.0f, 127.0f, 10.0f },
    { 100.0f, 0.0f, 127.0f, 10.0f },
    { 100.0f, 0.0f, 127.0f, 10.0f },
};
u32 lbl_3_data_8894[6] = {
    0x01, 0x01, 0x01, 0x01, 0x61, 0x61,
};
f32 lbl_3_data_88AC[3] = { 50.0f, 50.0f, 1.0f };
s16 lbl_3_data_88B8[0x12] = {
    0x2000, 0x3B00, 0x3, 0x2D, 0x46, 0x0,
    0x2000, 0x3FFF, 0x1, 0x3C, 0x7F, 0x0,
    0x2000, 0x3FFF, 0x14, 0xA5, 0x7F, 0x0,
};
u8 lbl_3_data_88DC[2] = {
    0x03, 0x03,
};
static SeqEntry lbl_3_data_88E0[19] = {
    { 0x1D, 0x00, 0x0 }, { 0x1D, 0x01, 0x1 }, { 0x1D, 0x02, 0x2 }, { 0x1D, 0x03, 0x3 },
    { 0x1D, 0x04, 0x4 }, { 0x1D, 0x06, 0x5 }, { 0x1D, 0x05, 0x6 }, { 0x1D, 0x07, 0x7 },
    { 0x1D, 0x08, 0x8 }, { 0x1D, 0x09, 0x9 }, { 0x1D, 0x0A, 0xA }, { 0x1D, 0x0B, 0xB },
    { 0x1D, 0x0C, 0xC }, { 0x1D, 0x0D, 0xD }, { 0x1D, 0x0E, 0xE }, { 0x1D, 0x0F, 0xF },
    { 0x1D, 0x10, 0x10 }, { 0x1D, 0x11, 0x11 }, { 0x1D, 0x12, 0x12 },
};
static SeqEntry lbl_3_data_8954[1] = {
    { 0x36, 0x15, 0x0 },
};
u8 lbl_3_data_895C[0x16] = {
    0x16, 0x17, 0x19, 0x1A, 0x1D, 0x1E, 0x1F, 0x20, 0x22, 0x23, 0x24, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E,
    0x2F, 0x31, 0x32, 0x33, 0x34, 0x35,
};
EmitterParams lbl_3_data_8974[17] = {
    { { -5000000, -4000000, 23000000 }, 30000000, 0, 110, 30, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }, 1 },
    { { -5000000, 0, 19000000 }, 40000000, 0, 127, 50, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }, 1 },
    { { 0, 0, 6000000 }, 8000000, 0, 90, 30, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }, 16 },
    { { 0, 0, 0 }, 20000000, 0, 90, 30, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 32 },
    { { -5000000, -1000000, 5000000 }, 30000000, 0, 70, 10, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 32 },
    { { 0, 0, 5000000 }, 20000000, 0, 50, 15, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 32 },
    { { -5000000, 0, 19000000 }, 40000000, 0, 90, 35, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }, 1 },
    { { 0, 0, 0 }, 20000000, 0, 60, 40, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 8 },
    { { 0, 0, 0 }, 20000000, 0, 110, 90, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 2 },
    { { 0, 0, 0 }, 20000000, 0, 127, 100, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 2 },
    { { 0, 0, 0 }, 20000000, 0, 127, 100, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 4 },
    { { 0, 0, 0 }, 20000000, 0, 127, 100, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 4 },
    { { 0, 0, 0 }, 20000000, 0, 127, 100, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 4 },
    { { 0, 0, 0 }, 20000000, 0, 127, 100, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 4 },
    { { 0, 0, 0 }, 20000000, 0, 127, 100, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40 }, 4 },
    { { 0, 0, 0 }, 20000000, 0, 127, 0, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }, 1 },
    { { 0, 0, 0 }, 20000000, 0, 127, 0, { 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }, 1 },
};
static SND_FVECTOR lbl_3_data_8D70 = { 0.0f, -1.0f, 0.0f };
Vec lbl_3_data_8D7C = { 0.0f, 0.0f, 0.0f };

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

// .text:0x00090F48 size:0x11C mapped:0x806CFFDC
int fn_3_90F48(void) {
    int charID;
    int idx;
    int group;
    u8 slot;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE) {
        charID = lbl_3_common_bss_34C58._2D;
    } else if (g_d_GameSettings.GameModeSelected == GAME_TYPE_MINIGAMES ||
               g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        charID = g_Minigame.minigameControlStruct._4[lbl_3_common_bss_34C58._2C / 2];
    } else if (g_GameLogic.gameStatus == 0xE) {
        charID = lbl_3_common_bss_34C58._2D;
    } else {
        slot = lbl_800EF808._39A;
        charID = inMemRoster[slot / 9][slot % 9].stats.CharID;
    }
    idx = fn_800698F8(charID);
    group = idx + 5;
    fn_80021518(lbl_3_data_8148[idx], lbl_800EF808.groups[group]);
    return 0;
}

// .text:0x00090DD8 size:0x170 mapped:0x806CFE6C
BOOL fn_3_90DD8(void) {
    SoundLoadTask* task = lbl_803CC1B8;
    u8 state = lbl_3_common_bss_34C58._2C;
    int player = state / 2;
    int charID;
    int group;
    int i;

    if (state == 0 || state == 2 || state == 4 || state == 6) {
        if (g_Minigame.minigameControlStruct.characterIndex[player] < 0) {
            lbl_3_common_bss_34C58._2C += 2;
            return FALSE;
        }
        charID = lbl_800E8558[g_Minigame.minigameControlStruct._4[player]][1];
        if (player != 0) {
            for (i = 0; i < player; i++) {
                if (charID == lbl_800E8558[g_Minigame.minigameControlStruct._4[i]][1]) {
                    if ((lbl_3_common_bss_34C58._2C += 2) >= 8) {
                        g_Minigame._19AB = 1;
                        return TRUE;
                    }
                    return FALSE;
                }
            }
        }
        group = fn_800698F8(charID);
        fn_800216F8(group + 5, fn_3_90F48);
        lbl_3_common_bss_34C58._2C++;
    } else if (task->_10 != 0) {
        if (++lbl_3_common_bss_34C58._2C >= 8) {
            g_Minigame._19AB = 1;
            return TRUE;
        }
    }
    return FALSE;
}

// .text:0x00090CB0 size:0x128 mapped:0x806CFD44
void fn_3_90CB0(void) {
    int team;
    int i;
    int j;
    BOOL dup;
    int idx;

    if (g_Minigame._19AB != 0) {
        for (team = 3; team >= 0; team--) {
            for (i = 0; i < 4; i++) {
                if (g_Minigame.minigameControlStruct.characterIndex[i] == team) {
                    dup = FALSE;
                    for (j = 0; j < i; j++) {
                        if (lbl_800E8558[g_Minigame.minigameControlStruct._4[i]][1] ==
                            lbl_800E8558[g_Minigame.minigameControlStruct._4[j]][1]) {
                            dup = TRUE;
                            break;
                        }
                    }
                    if (!dup) {
                        break;
                    }
                }
            }
            if (i < 4) {
                idx = fn_800698F8(inMemRoster[0][team].stats.CharID) + 5;
                if (lbl_800EF808.groups[idx] != NULL) {
                    fn_800214D0();
                    fn_800ACFB0(lbl_800EF808.groups[idx]);
                    lbl_800EF808.groups[idx] = NULL;
                }
            }
        }
    }
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

// .text:0x0009056C size:0x108 mapped:0x806CF600
BOOL fn_3_9056C(s32 song) {
    SeqEntry* entry;

    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_PRACTICE) {
        entry = &lbl_3_data_88E0[song];
    } else {
        entry = &lbl_3_data_8954[song];
    }
    if (sndSeqGetValid(lbl_3_common_bss_34C58._08)) {
        sndSeqVolume(0, 0, lbl_3_common_bss_34C58._08, 1);
        return FALSE;
    }
    lbl_3_common_bss_34C58._08 = sndSeqPlayEx(entry->group, entry->song, (void*)lbl_3_bss_1774[song], NULL, 0);
    sndSeqVolume(lbl_800EF808._391 = lbl_3_data_830C[song][0], 0, lbl_3_common_bss_34C58._08, 0);
    return TRUE;
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
SND_VOICEID fn_3_90150(s32 charID, s32 sound) {
    int fxid = lbl_3_data_8168[charID] + sound;
    int vol = lbl_3_data_8530[0][sound];
    int ctrl;
    SND_VOICEID vid;
    vol = vol * lbl_3_data_8830;
    ctrl = lbl_3_data_8530[1][sound];
    ctrl = ctrl * lbl_3_data_8830;
    vid = sndFXStartEx(fxid, vol, 0x3F, 0);
    sndFXCtrl(vid, 0x5B, ctrl);
    return vid;
}

// .text:0x00090064 size:0xEC mapped:0x806CF0F8
SND_VOICEID fn_3_90064(int id) {
    int i;

    if (g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES) {
        OSPanic("m_sound.c", 0x402, "no mini game");
    }
    for (i = 0; i < 0x39; i++) {
        if (id == lbl_3_data_81FC[i]) {
            break;
        }
    }
    if (i == 0x39) {
        OSPanic("m_sound.c", 0x40D, "no entry mini_se_no");
    }
    return sndFXStartEx(id, lbl_3_data_84F4[i], 0x3F, 0);
}

// .text:0x0008FF5C size:0x108 mapped:0x806CEFF0
SND_VOICEID fn_3_8FF5C(s32 sound, f32 x, f32 y, f32 z) {
    int sx;
    int sy;
    int pan = 0x3F;
    SND_VOICEID vid;

    if (lbl_800EF808._396 == 1) {
        fn_3_1650C(&sx, &sy, TRUE, x, -y, z);
        if (sx < 0) {
            pan = 0;
        } else if (sx > 640) {
            pan = 0x7F;
        } else {
            pan = 127.0f * (sx / 640.0f);
        }
    }
    vid = sndFXStartEx(sound, lbl_3_data_8338[sound - 0x151][0], pan, 0);
    sndFXCtrl(vid, 0x5B, lbl_3_data_8338[sound - 0x151][1]);
    return vid;
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
    int height;
    int h;
    f32 t;

    if ((g_GameLogic.secondaryGameMode == 0 || (u8)(g_GameLogic.secondaryGameMode - 11) <= 4 || g_GameLogic.secondaryGameMode == 16) &&
        !(g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE &&
          (g_Practice._19F != 0 || g_Practice.tutorialState == 0)) &&
        g_GameLogic.gameStatus == 2 && g_Ball.AtBat_Contact_BallPos.y > 3.0f && g_Ball.maxYOfHit > 8.0f &&
        !(g_Ball.AtBat_Contact_BallPos.y < 6.0f && g_Ball.physicsSubstruct.velocity.y < 0.0f) &&
        g_Ball.collisionRelated == 0 && g_Ball.ballCughtByPlantInd == 0 && g_Ball.deadBallReason == 0 &&
        g_Ball.AtBat_ContactResult != 1 && (u16)(g_Ball.AtBat_ContactResult - 2) > 1) {
        if (lbl_3_common_bss_34C58._18 == SND_ID_ERROR) {
            lbl_3_common_bss_34C58._18 = playSoundEffect(0x17F);
            sndFXCtrl(lbl_3_common_bss_34C58._18, 7, lbl_3_data_88B8[4]);
        }
        h = g_Ball.AtBat_Contact_BallPos.y;
        height = h;
        if (h > lbl_3_data_88B8[3]) {
            height = lbl_3_data_88B8[3];
        }
        height -= lbl_3_data_88B8[2];
        t = (f32)height / (lbl_3_data_88B8[3] - lbl_3_data_88B8[2]);
        sndFXCtrl14(lbl_3_common_bss_34C58._18, 0x80,
                    lbl_3_data_88B8[0] + (int)(t * (lbl_3_data_88B8[1] - lbl_3_data_88B8[0])));
    } else if (lbl_3_common_bss_34C58._18 != SND_ID_ERROR) {
        sndFXKeyOff(lbl_3_common_bss_34C58._18);
        lbl_3_common_bss_34C58._18 = SND_ID_ERROR;
    }
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
// 99.37%: the target tests the stadium with four separate compares (this merges 2 and 3 into a
// range check) and tests the flag through (-x | x) >> 31; "dome = dome != FALSE;" reproduces
// that test (99.78%) but is no plausible source
void fn_3_8F21C(void) {
    BOOL dome = FALSE;
    BOOL stop = FALSE;
    BOOL out;
    int i;

    if (g_d_GameSettings.StadiumID == 1 || g_d_GameSettings.StadiumID == 2 || g_d_GameSettings.StadiumID == 3 ||
        g_d_GameSettings.StadiumID == 5) {
        dome = TRUE;
    }
    if (dome != FALSE) {
        if (g_FieldingLogic._107 != 0) {
            for (i = 1; i < 4; i++) {
                if (lbl_3_common_bss_34C58._26 <= 1 && g_Runners[i].runnerOnFieldOrOutOrScored == 2) {
                    stop = TRUE;
                    goto stop_sounds;
                }
            }
        }
        if (g_Ball.framesSinceHit > 0 &&
            ((g_Ball.ballInitialHitDoneInd != 0 && g_Ball.AtBat_ContactResult == 1 && g_Ball.ballZoneAwayFromHome >= 3 &&
              lbl_3_common_bss_34C58._26 < 2) ||
             (g_Runners[0].runnerOnFieldOrOutOrScored == 1 && g_Runners[0].currentBase != 0 && g_Runners[0].forceOutCd == 0 &&
              (g_Ball.AtBat_ContactResult == 1 || g_Ball.AtBat_ContactResult == 2) && g_Strikes.outs == g_Strikes.storedOuts))) {
            lbl_3_common_bss_34C58._26 = 2;
            if (lbl_3_common_bss_34C58.voices[2] == SND_ID_ERROR) {
                lbl_3_common_bss_34C58.voices[2] = sndFXStartEx(0x156, 0, 0x3F, 0);
                if (g_Stats.replayInd == 0 && g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES) {
                    playSoundEffect(0x196);
                }
            }
        }
        return;
    }

    if (g_GameLogic.gameStatus == 3) {
        stop = TRUE;
    } else if (g_GameLogic.gameStatus == 1) {
        if (g_Ball.pitchHangtimeCounter == 10) {
            for (i = 1; i < 4; i++) {
                if (g_Runners[i].runnerOnFieldOrOutOrScored == 1 && g_Runners[i].furthestBaseForcedToGoToOnWalk != 0) {
                    if (lbl_3_common_bss_34C58.voices[1] == SND_ID_ERROR) {
                        lbl_3_common_bss_34C58.voices[1] = playSoundEffect(0x155);
                    }
                    break;
                }
            }
        }
    } else if (g_FieldingLogic._107 != 0) {
        for (i = 1; i < 4; i++) {
            if (lbl_3_common_bss_34C58._26 == 0 &&
                ((g_Runners[i].runnerOnFieldOrOutOrScored == 1 && g_Runners[i].baseStandingOn > i) ||
                 g_Runners[i].runnerOnFieldOrOutOrScored == 3)) {
                lbl_3_common_bss_34C58._26 = 1;
                if (lbl_3_common_bss_34C58.voices[1] == SND_ID_ERROR) {
                    lbl_3_common_bss_34C58.voices[1] = playSoundEffect(0x155);
                }
            } else if (lbl_3_common_bss_34C58._26 <= 1 && g_Runners[i].runnerOnFieldOrOutOrScored == 2) {
                lbl_3_common_bss_34C58._26 = 2;
                playSoundEffect(0x158);
                stop = TRUE;
                break;
            }
        }
    } else if (g_Ball.framesSinceHit > 0) {
        if (g_Ball.framesSinceHit > 20 && lbl_3_common_bss_34C58._26 == 0) {
            lbl_3_common_bss_34C58._26 = 1;
            if (g_Batter.isBunting != 0) {
                if ((g_RunningLogic._2 == 1 || (g_RunningLogic._2 & 0x1000)) &&
                    lbl_3_common_bss_34C58.voices[1] == SND_ID_ERROR) {
                    lbl_3_common_bss_34C58.voices[1] = playSoundEffect(0x155);
                }
            } else if (g_Ball.Hit_HorizontalPower > 150 &&
                       (g_Ball.Hit_VerticalAngle > 0xF80 || g_Ball.Hit_VerticalAngle < 0x200) &&
                       g_Ball.Hit_HorizontalAngle > 0x80 && g_Ball.Hit_HorizontalAngle < 0x780 &&
                       lbl_3_common_bss_34C58.voices[1] == SND_ID_ERROR) {
                lbl_3_common_bss_34C58.voices[1] = playSoundEffect(0x155);
            }
        }
        if ((g_Ball.ballInitialHitDoneInd != 0 && g_Ball.AtBat_ContactResult == 1 && g_Ball.ballZoneAwayFromHome >= 3 &&
             lbl_3_common_bss_34C58._26 < 2) ||
            (g_Runners[0].runnerOnFieldOrOutOrScored == 1 && g_Runners[0].currentBase != 0 && g_Runners[0].forceOutCd == 0 &&
             (g_Ball.AtBat_ContactResult == 1 || g_Ball.AtBat_ContactResult == 2) && g_Strikes.outs == g_Strikes.storedOuts)) {
            lbl_3_common_bss_34C58._26 = 2;
            if (lbl_3_common_bss_34C58.voices[2] == SND_ID_ERROR) {
                lbl_3_common_bss_34C58.voices[2] = playSoundEffect(0x156);
                if (g_Stats.replayInd == 0 && g_d_GameSettings.GameModeSelected != GAME_TYPE_MINIGAMES) {
                    playSoundEffect(0x196);
                }
            }
        }
        if (g_Ball.deadBallReason == 1 && lbl_3_common_bss_34C58._26 < 9) {
            lbl_3_common_bss_34C58._26 = 9;
            if (lbl_3_common_bss_34C58.voices[2] == SND_ID_ERROR) {
                lbl_3_common_bss_34C58.voices[2] = playSoundEffect(0x156);
            }
        }
        if (g_Ball.AtBat_ContactResult == -1 && lbl_3_common_bss_34C58._26 < 9) {
            if (g_Ball.deadBallReason == 2) {
                if (g_Ball.matchFramesAndBallAngle.ballOverWallFrames == 30) {
                    lbl_3_common_bss_34C58._26 = 9;
                    stop = TRUE;
                    if (fn_3_B7D6C(g_Ball.deadballLastLoc.x, g_Ball.deadballLastLoc.z)) {
                        playSoundEffect(0x158);
                    }
                }
            } else if (g_Ball.framesSinceBallHitGroundOrWasCaught == 30) {
                lbl_3_common_bss_34C58._26 = 9;
                stop = TRUE;
                if (fn_3_B7D6C(g_Ball.landingSpotLocation.x, g_Ball.landingSpotLocation.z) &&
                    (g_Ball.ballZoneAwayFromHome == 4 ||
                     (g_Ball.Hit_HorizontalPower > 150 &&
                      (g_Ball.Hit_VerticalAngle > 0xFC0 || g_Ball.Hit_VerticalAngle < 0x200)))) {
                    playSoundEffect(0x157);
                }
            }
        }
        if (g_Runners[0].runnerOnFieldOrOutOrScored == 2 && g_Runners[0].framesSinceOut == 20 && g_Scores._C2 == 0 &&
            (g_Runners[3].runnerOnFieldOrOutOrScored != 1 || !(g_Runners[3].fractionalBasesRan > 3.5f))) {
            out = FALSE;
            if (lbl_3_common_bss_32A94._2 == 0x15 || lbl_3_common_bss_32A94._2 == 0x18 ||
                lbl_3_common_bss_32A94._2 == 0x16) {
                out = TRUE;
            }
            if (lbl_3_common_bss_32A94._2 == 0x12 &&
                (g_Ball.ballZoneAwayFromHome <= 1 ||
                 fn_3_B7E10(g_Ball.AtBat_Contact_BallPos.x, g_Ball.AtBat_Contact_BallPos.z))) {
                out = TRUE;
            }
            if (lbl_3_common_bss_32A94._2 == 0x13 && g_Ball.ballZoneAwayFromHome <= 1 && g_Ball.Hit_HorizontalPower > 180) {
                out = TRUE;
            }
            if (out) {
                stop = TRUE;
                playSoundEffect(0x157);
            }
        }
    }
stop_sounds:
    if (stop) {
        if (lbl_3_common_bss_34C58.voices[1] != SND_ID_ERROR) {
            sndFXKeyOff(lbl_3_common_bss_34C58.voices[1]);
            lbl_3_common_bss_34C58.voices[1] = SND_ID_ERROR;
        }
        if (lbl_3_common_bss_34C58.voices[2] != SND_ID_ERROR) {
            sndFXKeyOff(lbl_3_common_bss_34C58.voices[2]);
            lbl_3_common_bss_34C58.voices[2] = SND_ID_ERROR;
        }
    }
    if (g_GameLogic.gameStatus == 0xB) {
        for (i = 0; i < 3; i++) {
            if (lbl_3_common_bss_34C58.voices[i] != SND_ID_ERROR) {
                sndFXKeyOff(lbl_3_common_bss_34C58.voices[i]);
                lbl_3_common_bss_34C58.voices[i] = SND_ID_ERROR;
            }
        }
    }
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
    camera_803c639c_s* cam;
    Vec pos;
    Vec vel;
    Vec dir;

    fn_3_8CD74();
    cam = fn_80052734(0);
    pos.x = cam->eye.x;
    pos.y = cam->eye.y;
    pos.z = cam->eye.z;
    vel.x = 0.0f;
    vel.y = 0.0f;
    vel.z = 0.0f;
    PSVECSubtract(&cam->target, &cam->eye, &dir);
    if (PSVECMag(&dir)) {
        PSVECNormalize(&dir, &dir);
    }
    fn_3_8B964((SND_FVECTOR*)&pos, (SND_FVECTOR*)&vel, (SND_FVECTOR*)&dir);
}

// .text:0x0008CD74 size:0xC4C mapped:0x806CBE08
void fn_3_8CD74(void) {
    UnkPlayer8CD74* player;

    if (g_GameLogic.gameStatus == 0xB || g_Minigame.pauseInd != 0) {
        return;
    }
    if (g_GameLogic.gameStatus == 1) {
        if (g_Pitcher.windupCountdownUntilBallReleased == 0 && g_Ball.pitchHangtimeCounter == 0) {
            if (lbl_3_common_bss_34C58._34 == 0) {
                if (g_d_GameSettings.GameModeSelected == GAME_TYPE_PRACTICE && g_Practice.practiceLevel == 4) {
                    playSoundEffect(0x1AE);
                } else if (g_Minigame.GameMode_MiniGame != 1 && g_Minigame.GameMode_MiniGame != 3) {
                    if (g_GameLogic.PauseSimulationFrameCount == 5) {
                        fn_3_90220(g_Pitcher.charID, 6);
                    } else if (g_Pitcher.ChargePitchType == 3) {
                        playSoundEffect(0x188);
                        fn_3_90220(g_Pitcher.charID, 6);
                    } else if (g_Pitcher.ChargePitchType != 0) {
                        if (g_Pitcher.starPitchType == 0) {
                            fn_3_90220(g_Pitcher.charID, 5);
                        }
                        playSoundEffect(0x187);
                    } else if (g_Pitcher.TypeOfPitch == 2) {
                        playSoundEffect(0x17D);
                    } else {
                        playSoundEffect(0x186);
                    }
                }
            }
            lbl_3_common_bss_34C58._34 = 1;
        }
        if (g_Minigame.GameMode_MiniGame == 1 && g_Ball.pitchHangtimeCounter == 1 && g_Pitcher.starPitchInd != 0) {
            playSoundEffect(0x19E);
            lbl_3_bss_177C = playSoundEffect(0x18F);
        }
        if (g_GameLogic.PauseSimulationFrameCount == 1 && g_Pitcher.starPitchType != 0) {
            playSoundEffect(0x19E);
            switch (g_Pitcher.starPitchType) {
            case 1:
            case 2:
                lbl_3_bss_177C = playSoundEffect(0x18F);
                break;
            case 3:
            case 4:
                lbl_3_bss_177C = playSoundEffect(0x18C);
                break;
            case 5:
            case 6:
                lbl_3_bss_177C = playSoundEffect(0x18D);
                break;
            case 7:
            case 8:
                lbl_3_bss_177C = playSoundEffect(0x190);
                break;
            case 9:
            case 10:
                lbl_3_bss_177C = playSoundEffect(0x18E);
                break;
            case 11:
            case 12:
                lbl_3_bss_177C = playSoundEffect(0x19A);
                break;
            }
        }
        if (g_Ball.pitchHangtimeCounter > 0 && g_Pitcher.framesUntilUnhittable < 30 && lbl_8036E548._307D == 0) {
            player = lbl_8036E548._2C74;
            if (g_d_GameSettings.minigamesEnabled) {
                player = &lbl_8036E548._C04[g_Minigame.minigameControlStruct.characterIndex[g_Minigame.rosterID]];
            }
            if (player != NULL && player->_62 == 0x60 && player->_6A == 5) {
                fn_3_90220(g_Batter.charID, 3);
            }
        }
    }
    if (lbl_8036E548._307D == 0) {
        if (lbl_3_common_bss_34C58._2B != 0 && g_Ball.framesSinceHit == 2) {
            lbl_3_common_bss_34C58._2B = 0;
            sndFXKeyOff(lbl_3_bss_177C);
            if (g_Batter.isBunting) {
                playSoundEffect(0x153);
            } else if (g_Batter.captainStarSwingActivated != 0) {
                switch (g_Batter.captainStarSwingActivated) {
                case 1:
                case 2:
                    lbl_3_bss_1778 = playSoundEffect(0x194);
                    break;
                case 3:
                case 4:
                    lbl_3_bss_1778 = playSoundEffect(0x191);
                    break;
                case 5:
                case 6:
                    lbl_3_bss_1778 = playSoundEffect(0x192);
                    break;
                case 7:
                case 8:
                    lbl_3_bss_1778 = playSoundEffect(0x195);
                    break;
                case 9:
                case 10:
                    lbl_3_bss_1778 = playSoundEffect(0x193);
                    break;
                case 11:
                case 12:
                    lbl_3_bss_1778 = playSoundEffect(0x199);
                    lbl_3_bss_1760 = 0;
                    break;
                }
                playSoundEffect(0x184);
                playSoundEffect(0x185);
                fn_3_90220(g_Batter.charID, 0);
            } else if (g_Batter.charID == 2) {
                playSoundEffect(0x1AF);
            } else if (g_Batter.charID == 0x26) {
                playSoundEffect(0x1B0);
            } else if (g_Batter.displayContactSprite) {
                playSoundEffect(0x184);
                playSoundEffect(0x185);
            } else if (g_Batter.contactType == 2) {
                playSoundEffect(0x184);
                fn_3_90220(g_Batter.charID, 0);
            } else if (g_Batter.contactType >= 1 && g_Batter.contactType <= 3) {
                fn_3_90220(g_Batter.charID, 0);
                playSoundEffect(0x184);
            } else {
                playSoundEffect(0x183);
            }
        }
        if (g_Batter.chargeStatus == 1 && g_GameLogic.gameStatus == 1 && g_Batter.chargeFrames < g_Batter.frameChargeDownBegins &&
            g_Batter.chargeFrames == 1) {
            lbl_3_common_bss_34C58._1C = fn_3_90220(g_Batter.charID, 2);
        }
    }
    if ((g_Batter.captainStarSwingActivated == 11 || g_Batter.captainStarSwingActivated == 11) && lbl_3_bss_1760 == 0 && g_Ball.physicsSubstruct.velocity.y <= -0.09 &&
        g_Ball.physicsSubstruct.velocity.y >= -0.1) {
        sndFXKeyOff(lbl_3_bss_177C);
        lbl_3_bss_1778 = playSoundEffect(0x19B);
        lbl_3_bss_1760 = 1;
    }
    if (g_GameLogic.gameStatus != 1 && g_GameLogic.gameStatus != 2 && lbl_3_bss_177C != 0) {
        sndFXKeyOff(lbl_3_bss_177C);
    }
    if (g_Ball.AtBat_Contact_BallPos.z < -3.0f && lbl_3_bss_177C != 0) {
        sndFXKeyOff(lbl_3_bss_177C);
    }
    if (g_Pitcher.strikeOutOrWalk == 3) {
        sndFXKeyOff(lbl_3_bss_177C);
    }
    if (lbl_3_bss_1778 != 0 && (g_Ball.currentStarSwing == 0 || g_Ball.deadBallReason != 0)) {
        sndFXKeyOff(lbl_3_bss_1778);
    }
}

// .text:0x0008C5C8 size:0x7AC mapped:0x806CB65C
void fn_3_8C5C8(void) {
    return;
}

// .text:0x0008C4F0 size:0xD8 mapped:0x806CB584
BOOL fn_3_8C4F0(u32 steps, u8 target) {
    u32 vol = fn_800A8864();
    int hi = (vol >> 8) & 0xFF;
    u8 lo = vol & 0xFF;

    lbl_3_common_bss_34C58._2F = 0;
    if (lbl_3_bss_1761 == 0) {
        lbl_3_bss_1761 = 1;
        lbl_3_bss_1771 = hi / steps;
        lbl_3_bss_1770 = lo / steps;
    }
    hi -= lbl_3_bss_1771;
    if ((s16)hi <= target || steps == 1) {
        lbl_3_bss_1761 = 0;
        fn_800A8878(target, target);
        return FALSE;
    }
    fn_800A8878(hi, lo - lbl_3_bss_1770);
    return TRUE;
}

// .text:0x0008C2DC size:0x214 mapped:0x806CB370
// 98.80%: the setup block takes r0/r5 for the constant 1 and 0x4330 the other way round
BOOL fn_3_8C2DC(u32 steps, s32 sel) {
    u32 vol = fn_800A8864();
    u8 target;
    f32 cur;

    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        target = lbl_800E88A4[9][(u8)sel];
    } else if (lbl_3_common_bss_34C58._20 == 0x16) {
        target = lbl_800E88A4[6][(u8)sel];
    } else if (g_GameLogic.gameStatus == 0xE) {
        target = lbl_800E88A4[7][(u8)sel];
    } else if (g_GameLogic.gameStatus == 0x17) {
        target = lbl_800E88A4[8][(u8)sel];
    } else {
        target = lbl_800E88A4[g_d_GameSettings.StadiumID][(u8)sel];
    }
    cur = (int)((vol >> 8) & 0xFF);
    if (cur > lbl_3_bss_1764) {
        lbl_3_bss_1764 = cur;
    }
    if (!lbl_3_common_bss_34C58._2F) {
        lbl_3_common_bss_34C58._2F = 1;
        lbl_3_bss_176C = (f32)target / (f32)steps;
        lbl_3_bss_1764 = cur;
    }
    lbl_3_bss_1764 += lbl_3_bss_176C;
    fn_800A8878(lbl_3_bss_1764, lbl_3_bss_1764);
    if (lbl_3_bss_1764 >= target) {
        lbl_3_common_bss_34C58._2F = 0;
        return FALSE;
    }
    return TRUE;
}

// .text:0x0008C104 size:0x1D8 mapped:0x806CB198
// 99.66%: the inlined fn_3_8B258 swaps its queue pointer and head registers, as in fn_3_8C07C
void fn_3_8C104(s32 vol) {
    int stadium;
    u8 level;
    int sel = 0;

    if (!lbl_800EF808._398) {
        return;
    }
    if (vol == -2) {
        sel = 1;
    }
    if (g_d_GameSettings.GameModeSelected == GAME_TYPE_TOY_FIELD) {
        stadium = 9;
        level = lbl_800E88A4[stadium][sel];
    } else if (g_GameLogic.gameStatus == 0x24) {
        stadium = 7;
        level = lbl_800E88A4[stadium][sel];
    } else if (lbl_3_common_bss_34C58._20 == 0x16) {
        stadium = 6;
        level = lbl_800E88A4[stadium][sel];
    } else if (lbl_3_common_bss_34C58._20 == 0x17) {
        stadium = 14;
        level = lbl_800E88A4[stadium][sel];
    } else if (g_GameLogic.gameStatus == 0xE) {
        stadium = 7;
        level = lbl_800E88A4[stadium][sel];
    } else if (g_GameLogic.gameStatus == 0x17) {
        stadium = 8;
        level = lbl_800E88A4[stadium][sel];
    } else {
        stadium = g_d_GameSettings.StadiumID;
        level = lbl_800E88A4[stadium][sel];
    }
    if (vol >= 0) {
        level = vol;
    }
    fn_3_8B258(0, stadium, level);
    if (level == 0) {
        fn_800A8878(level, level);
    }
}

// .text:0x0008C07C size:0x88 mapped:0x806CB110
// 98.82%: the inlined fn_3_8B258 gets the queue pointer in r8 and its head in r7, where the
// target (and every other inlined copy) has the pointer in the lower register
void fn_3_8C07C(void) {
    fn_3_8B258(4, 0, 0);
}

// .text:0x0008BE8C size:0x1F0 mapped:0x806CAF20
// 92.66%: the target keeps the clearing loop's entry test (li r6,0 first, cmpwi r6,100; bge)
// and walks the arrays from r3; every counter form tried folds the test away
void fn_3_8BE8C(void) {
    SND_FVECTOR pos = { 0.0f, 0.0f, 0.0f };
    int i;

    for (i = 0; i < 100; i++) {
        lbl_3_common_bss_32B20.emitterType[i] = 0xFF;
        lbl_3_common_bss_32B20.emitterActive[i] = 0;
        lbl_3_common_bss_32B20._2098[i] = 0;
    }
    lbl_3_common_bss_32B20._20FC = 0xFF;
    lbl_3_common_bss_32B20._20FD = 0;
    fn_3_8B9BC(&pos);
    fn_3_8B804();
}

// .text:0x0008BDF4 size:0x98 mapped:0x806CAE88
void fn_3_8BDF4(void) {
    fn_3_8B804();
    fn_3_8B7DC();
}

// .text:0x0008BBC4 size:0x230 mapped:0x806CAC58
s32 fn_3_8BBC4(u32 id, Vec* pos, Vec* dir, s32 type) {
    int i;
    Vec defPos;

    for (i = 0; i < 100; i++) {
        if (!lbl_3_common_bss_32B20.emitterActive[i] || !sndCheckEmitter(&lbl_3_common_bss_32B20.emitters[i])) {
            lbl_3_common_bss_32B20.emitterType[i] = type;
            lbl_3_common_bss_32B20.emitterActive[i] = 1;
            lbl_3_common_bss_32B20._2098[i] = 0;
            if (pos == NULL) {
                defPos.x = lbl_3_data_8974[type].pos[0] / 100000.0f;
                defPos.y = lbl_3_data_8974[type].pos[1] / 100000.0f;
                defPos.z = lbl_3_data_8974[type].pos[2] / 100000.0f;
                pos = &defPos;
            }
            if (dir == NULL) {
                dir = &lbl_3_data_8D7C;
            }
            sndAddEmitter(&lbl_3_common_bss_32B20.emitters[i], (SND_FVECTOR*)pos, (SND_FVECTOR*)dir,
                          lbl_3_data_8974[type].maxDis / 100000.0f, lbl_3_data_8974[type].comp / 100000.0f,
                          lbl_3_data_8974[type].flags[0] | lbl_3_data_8974[type].flags[1] |
                              lbl_3_data_8974[type].flags[2] | lbl_3_data_8974[type].flags[3] |
                              lbl_3_data_8974[type].flags[4] | lbl_3_data_8974[type].flags[5] |
                              lbl_3_data_8974[type].flags[6],
                          id, lbl_3_data_8974[type].maxVol, lbl_3_data_8974[type].minVol, NULL);
            return i;
        }
    }
    if (i == 100) {
        OSPanic("m_sound.c", 0xE4C, "No Empty Emitter");
    }
    return -1;
}

// .text:0x0008BA60 size:0x164 mapped:0x806CAAF4
void fn_3_8BA60(s32 handle, Vec* pos, Vec* dir) {
    SND_EMITTER* em;
    Vec defPos;
    u8 type;

    if (handle < 0 || handle >= 100 || !lbl_3_common_bss_32B20.emitterActive[handle]) {
        return;
    }
    em = &lbl_3_common_bss_32B20.emitters[handle];
    if (!sndCheckEmitter(em)) {
        lbl_3_common_bss_32B20.emitterActive[handle] = 0;
        return;
    }
    type = lbl_3_common_bss_32B20.emitterType[handle];
    if (pos == NULL) {
        defPos.x = lbl_3_data_8974[type].pos[0] / 100000.0f;
        defPos.y = lbl_3_data_8974[type].pos[1] / 100000.0f;
        defPos.z = lbl_3_data_8974[type].pos[2] / 100000.0f;
        pos = &defPos;
    }
    if (dir == NULL) {
        dir = &lbl_3_data_8D7C;
    }
    sndUpdateEmitter(em, (SND_FVECTOR*)pos, (SND_FVECTOR*)dir, lbl_3_data_8974[type].maxVol, NULL);
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
    SND_EMITTER* em;

    if (handle < 0 || handle >= 100 || !lbl_3_common_bss_32B20.emitterActive[handle]) {
        return;
    }
    em = &lbl_3_common_bss_32B20.emitters[handle];
    if (sndCheckEmitter(em)) {
        SND_FVECTOR pos = { 0.0f, 0.0f, 0.0f };
        SND_FVECTOR dir = { 0.0f, 0.0f, 1.0f };

        sndUpdateEmitter(em, &pos, &dir, 0, NULL);
        sndRemoveEmitter(em);
    }
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
void fn_3_8B718(Vec* pos, Vec* vel, Vec* dir) {
    camera_803c639c_s* cam = fn_80052734(0);

    if (pos != NULL) {
        pos->x = cam->eye.x;
        pos->y = cam->eye.y;
        pos->z = cam->eye.z;
    }
    if (vel != NULL) {
        vel->x = 0.0f;
        vel->y = 0.0f;
        vel->z = 0.0f;
    }
    if (dir != NULL) {
        PSVECSubtract(&cam->target, &cam->eye, dir);
        if (PSVECMag(dir)) {
            PSVECNormalize(dir, dir);
        }
    }
}

// .text:0x0008B318 size:0x400 mapped:0x806CA3AC
void fn_3_8B318(int arg) {
    u32 i;
    s32 j;

    if (arg == -1) {
        for (j = 0; j < 12; j++) {
            lbl_3_data_8530[1][j] = lbl_3_data_8278[j];
        }
    } else if (arg == 6) {
        for (i = 0; i < 7; i++) {
            lbl_3_data_84B8[i][1] = lbl_3_data_8270[i];
        }
        for (j = 0; j < 12; j++) {
            lbl_3_data_8530[1][j] = lbl_3_data_8278[j];
        }
        for (i = 0; i < 0x66; i++) {
            lbl_3_data_8338[i][1] = lbl_3_data_8284[i];
        }
    } else {
        for (i = 0; i < 7; i++) {
            lbl_3_data_84B8[i][1] = 0;
        }
        for (j = 0; j < 12; j++) {
            lbl_3_data_8530[1][j] = 0;
        }
        for (i = 0; i < 0x66; i++) {
            lbl_3_data_8338[i][1] = 0;
        }
    }
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
    lbl_3_bss_1768->queue[head * 3] = id;
    lbl_3_bss_1768->queue[head * 3 + 1] = state;
    lbl_3_bss_1768->queue[head * 3 + 2] = arg;
    return TRUE;
}

// .text:0x0008B094 size:0x1C4 mapped:0x806CA128
// 91.46%: the target reads the state byte as task + (tail * 3 + 0x17) with lbzx/stbx, keeping
// task in r31; this keeps task + tail * 3 instead and shifts the saved registers
void fn_3_8B094(void) {
    SoundLoadTask* task = lbl_803CC1B8;
    u8 tail;
    u8 next;
    s8 state;
    s8 arg;
    u8 id;

    if (task->head == task->tail) {
        return;
    }
    if (fn_800A88C8() == 3) {
        return;
    }
    tail = task->tail;
    next = (tail + 1) % 14;
    state = task->queue[tail * 3 + 1];
    arg = task->queue[tail * 3 + 2];
    id = task->queue[tail * 3];
    switch (state) {
    case 0:
        fn_800A8878(arg, arg);
        if (&lbl_8034E478[(s8)id] == fn_800A88C0()) {
            task->queue[tail * 3 + 1] = 2;
        } else {
            fn_800A8AB8(0);
            task->queue[tail * 3 + 1]++;
        }
        break;
    case 1:
        fn_800A8AB0(2);
        LoadFile(lbl_800E87B4[(s8)id], &lbl_8034E478[(s8)id], 0, 0, 1);
        task->queue[tail * 3 + 1]++;
    case 2:
        if (fn_800A8518(1)) {
            task->tail = next;
        }
        break;
    case 3:
        if (!fn_800A88D0() || fn_800A8518(2)) {
            task->tail = next;
        }
        break;
    case 4:
        if (fn_800A8518(3)) {
            task->tail = next;
        }
        break;
    }
}
