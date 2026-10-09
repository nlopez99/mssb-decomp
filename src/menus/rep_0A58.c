#include "header_rep_data.h"
#include "menus/rep_0A58.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/gx.h"
#include "Dolphin/vec.h"
#include "musyx/musyx.h"
#include "string.h"

typedef struct MenuTask0A58 {
    /* 0x00 */ u8 _00[0xC];
    /* 0x0C */ struct MenuTask0A58* _0C;
    /* 0x10 */ s16 _10;
    /* 0x12 */ u8 _12[0x14 - 0x12];
    /* 0x14 */ u16 _14;
    /* 0x16 */ s16 _16;
    /* 0x18 */ s16 _18;
    /* 0x1A */ s16 _1A;
    /* 0x1C */ u16 _1C;
    /* 0x1E */ u16 _1E;
    /* 0x20 */ u8 _20[0x28 - 0x20];
    /* 0x28 */ s8 _28;
} MenuTask0A58;

// One cell of a menu grid, copied from a MenuEntry0A58
typedef struct MenuItem0A58 {
    /* 0x00 */ void (*fn)(MenuTask0A58* task, struct MenuItem0A58* item);
    /* 0x04 */ s16 _04;
    /* 0x06 */ s16 _06;
    /* 0x08 */ s16 _08;
    /* 0x0A */ s16 _0A;
    /* 0x0C */ s16 _0C;
    /* 0x0E */ s16 _0E;
    /* 0x10 */ s16 _10;
    /* 0x12 */ s16 _12;
    /* 0x14 */ s16 _14;
    /* 0x16 */ u8 _16[0x18 - 0x16];
} MenuItem0A58; // size: 0x18

typedef struct MenuEntry0A58 {
    /* 0x0 */ void (*fn)(MenuTask0A58* task, MenuItem0A58* item);
    /* 0x4 */ s16 _04; // column
    /* 0x6 */ s16 _06;
    /* 0x8 */ s16 _08; // row
    /* 0xA */ s16 _0A;
    /* 0xC */ s16 _0C;
    /* 0xE */ s16 _0E;
} MenuEntry0A58; // size: 0x10

typedef struct AramEntry0A58 {
    /* 0x0 */ u32 _0[4];
} AramEntry0A58; // size: 0x10

typedef struct MenuSprite0A58 {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ u32 _54;
    /* 0x58 */ u32 _58;
    /* 0x5C */ u32 _5C;
    /* 0x60 */ u8 _60[0x68 - 0x60];
    /* 0x68 */ u8 _68;
} MenuSprite0A58;

typedef struct MenuSpriteRef0A58 {
    /* 0x0 */ MenuSprite0A58* _00;
    /* 0x4 */ u8 _04[0x8 - 0x4];
} MenuSpriteRef0A58; // size: 0x8

extern void* lbl_803CC1B8;
extern MenuSpriteRef0A58 lbl_80371C30[];
extern struct {
    /* 0x0000 */ u8 _0000[0x307A];
    /* 0x307A */ u8 _307A;
} lbl_8036E548;
// One text window per entry
typedef struct MenuTextWindow0A58 {
    /* 0x00 */ u8 _00[0x2F];
    /* 0x2F */ u8 _2F;
    /* 0x30 */ u8 _30;
    /* 0x31 */ u8 _31[0x38 - 0x31];
} MenuTextWindow0A58; // size: 0x38

extern struct {
    /* 0x000 */ MenuTextWindow0A58 _000[34];
    /* 0x770 */ u8 _770[0x7A0 - 0x770];
    /* 0x7A0 */ void* _7A0;
} lbl_80366B18;
extern struct {
    /* 0x000 */ u8 _000[0x715];
    /* 0x715 */ s8 _715;
} lbl_803C6CF8;
extern struct {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ void* _14;
} lbl_800EF808;
extern struct {
    /* 0x00 */ u8 _00[0x8];
    /* 0x08 */ u16 _08;
    /* 0x0A */ u8 _0A[0x10 - 0xA];
} lbl_800FEF70[];
extern struct {
    /* 0x00 */ u8 _00;
    /* 0x01 */ u8 _01[0x5 - 0x1];
    /* 0x05 */ u8 _05;
    /* 0x06 */ u8 _06[0x8 - 0x6];
    /* 0x08 */ u8 _08;
    /* 0x09 */ u8 _09;
} lbl_8034E978;

extern struct {
    /* 0x00000 */ MenuItem0A58 _00000[10][0x360];
    /* 0x32A00 */ u8 _32A00[0x32A04 - 0x32A00];
    /* 0x32A04 */ u8 _32A04[14][10];
} *lbl_2_bss_1A8230;

extern struct {
    /* 0x000000 */ MenuItem0A58 _000000[0x46][0x360];
    /* 0x162600 */ s16 _162600;
    /* 0x162602 */ u8 _162602[0x162604 - 0x162602];
    /* 0x162604 */ u8 _162604[14][0x46];
} *lbl_2_bss_1A8234;

extern struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ u8 _34;
} *lbl_2_bss_1A823C;

extern void* lbl_2_bss_1A8244;

extern struct {
    /* 0x0000 */ u8 _0000[0x44F2];
    /* 0x44F2 */ u8 _44F2;
} *lbl_2_bss_1A8248;

extern struct {
    /* 0x000000 */ u8 _000000[0x190000];
    /* 0x190000 */ s32 _190000;
    /* 0x190004 */ u8 _190004[0x1972BC - 0x190004];
    /* 0x1972BC */ u8 _1972BC;
    /* 0x1972BD */ u8 _1972BD[0x1976A0 - 0x1972BD];
    /* 0x1976A0 */ s32 _1976A0;
    /* 0x1976A4 */ s32 _1976A4;
    /* 0x1976A8 */ u8 _1976A8[0x1976F4 - 0x1976A8];
    /* 0x1976F4 */ s16 _1976F4;
    /* 0x1976F6 */ s16 _1976F6;
    /* 0x1976F8 */ u8 _1976F8[0x1976FA - 0x1976F8];
    /* 0x1976FA */ s16 _1976FA;
    /* 0x1976FC */ s16 _1976FC;
    /* 0x1976FE */ s16 _1976FE;
    /* 0x197700 */ s16 _197700;
    /* 0x197702 */ u8 _197702[0x19772E - 0x197702];
    /* 0x19772E */ s16 _19772E;
    /* 0x197730 */ u8 _197730[0x197746 - 0x197730];
    /* 0x197746 */ s16 _197746;
    /* 0x197748 */ u8 _197748[0x197752 - 0x197748];
    /* 0x197752 */ s16 _197752;
    /* 0x197754 */ s16 _197754;
    /* 0x197756 */ u8 _197756[0x197822 - 0x197756];
    /* 0x197822 */ s8 _197822;
    /* 0x197823 */ u8 _197823[0x197845 - 0x197823];
    /* 0x197845 */ u8 _197845;
    /* 0x197846 */ u8 _197846;
    /* 0x197847 */ u8 _197847;
    /* 0x197848 */ u8 _197848;
    /* 0x197849 */ u8 _197849;
    /* 0x19784A */ u8 _19784A;
    /* 0x19784B */ u8 _19784B[0x197863 - 0x19784B];
    /* 0x197863 */ s8 _197863;
} *lbl_2_bss_1A824C;

typedef struct MenuSave0A58 {
    /* 0x0000 */ u8 _0000[0x46F8];
    /* 0x46F8 */ s8 _46F8;
} MenuSave0A58;

extern MenuSave0A58 lbl_8034E9A0;
extern struct {
    /* 0x0 */ u8 _0[0x4];
    /* 0x4 */ u16 _4;
}* lbl_803CBBCC;
extern struct {
    /* 0x00 */ u8 _00[0x12];
    /* 0x12 */ u8 _12;
    /* 0x13 */ u8 _13;
} lbl_8037169C;
extern u8 lbl_800EFBA4[0x10];
extern u8 lbl_800E877C[0x38];
extern u8 lbl_80361B20[0x130];
extern u8 starMissionCompletionTracker[0x4508];
extern u8 lbl_2_bss_1A8250[0x1978FC];

extern void* fn_800B0A5C_insertQueue(void (*)(void), s32);
extern void fn_800B0A14_removeQueue(void);
extern void fn_80053FE8(void);
extern void fn_8001F228(void);
extern void fn_80021410(void);
extern void fn_800ACFB0(void* data);
extern void fn_80035B50(s32);
extern void* ARAMTransfer(AramEntry0A58* entry, int arg1, int arg2, u32 aram);
extern void fn_800111B4(void* arg);
extern int fn_80035838(AramEntry0A58* entry, int count);
extern void fn_800216F8(u8 group, int (*callback)(void));
extern int fn_800627C4(void);
extern void fn_80036134(MenuTask0A58* task, s32, s32, s32);
extern void fn_8000FE54(void);
extern void fn_8000F4B8(s32, s32, s32, s32);
extern void changeScene(u8, s16);
extern void fn_80062948(void);
extern void fn_8006295C(void);
extern u16 fn_8000F988(MenuTask0A58* task, s32, u16, s32, s32, s32);
extern void fn_8000FE08(s32 id, s32, s32);
extern void fn_800363D8(MenuTask0A58* task, s32, s32, s32, s32);
extern u32 fn_80036214(MenuTask0A58* task, s32, s32, s32);
extern void fn_8000F8F4(MenuTask0A58* task);

extern void fn_2_47CFC(void);
extern void fn_2_47FF8(void);
extern void fn_2_4E7EC(void);
extern void fn_2_4E858(MenuTask0A58* task);
extern void fn_2_4E878(MenuTask0A58* task, u32* layout);
extern void fn_2_68E68(void);
extern void fn_2_8E8A4(void);
extern void fn_2_489DC(void);
extern void fn_2_11A0(s32);
extern void fn_2_46D94(s16*, s16*, s32, s32, s32);
extern void fn_2_6AB3C(s32, Vec*, f32);
extern void fn_2_6ACF4(void);
extern void fn_2_71F60(void);
extern void fn_2_72054(s32, s32);
extern void fn_2_94604(s32);
extern void fn_2_9461C(s32);
extern void fn_2_94854(s32);
extern void fn_2_93C64(void);
// rep_0788's header declares these two stubs void(void); the callers here pass an index
extern void fn_2_1FF0C(s32 index);
extern void fn_2_1FF10(s32 index);
extern void fn_2_1FF14(s32 count);
extern void fn_2_1FFC4(s32 count);

static u32 lbl_2_data_1F8F0[0xB1] = {
    0x42415420, 0x46495253, 0x54000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x42415420, 0x4C415354, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x464C0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x50430000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x52520000, 0x524C0000, 0x4C520000, 0x4C4C0000, 0x4F464600, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4F4E0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x53454C45, 0x43542044, 0x45425547, 0x204D454E,
    0x55000000, 0x00000000, 0x00000000, 0x00000000, 0x48494445, 0x20434841, 0x52412053, 0x45540000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x53544152, 0x20504C41, 0x59455220, 0x53455400,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x4B4F4F50, 0x41205354, 0x4120464C, 0x41472053,
    0x45540000, 0x00000000, 0x00000000, 0x00000000, 0x4348414C, 0x4C45204C, 0x4556454C, 0x20465245,
    0x45205345, 0x54000000, 0x00000000, 0x00000000, 0x3150203E, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x434F4D31, 0x3E000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3250203E, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x434F4D32, 0x3E000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3350203E, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x434F4D33, 0x3E000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3450203E, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x434F4D34, 0x3E000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000FF0F, 0x0000880F, 0x00000FFF, 0x0000088F,
    0x0000F0FF, 0x0000808F, 0x0000F00F, 0x0000800F, 0x00000004, 0x000A0006, 0x00020009, 0x00010005,
    0x000B0011, 0x00030013, 0x00020608, 0x040A0103, 0x0705090B, 0x00000602, 0x08040A05, 0x0B030901,
    0x07000000,
};
s16 lbl_2_data_1FBB4[0xE8] = {
    0x00E8, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EF, 0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5,
    0x00F8, 0x00F9, 0x00FF, 0x0101, 0x0103, 0x0104, 0x0105, 0x0106, 0x0107, 0x0109, 0x010A, 0x010B,
    0x010C, 0x010D, 0x010E, 0x0111, 0x0112, 0x0113, 0x0115, 0x0116, 0x0117, 0x0119, 0x011A, 0x011B,
    0x011C, 0x011D, 0x011E, 0x011F, 0x0120, 0x0121, 0x0122, 0x0123, 0x0124, 0x0125, 0x0126, 0x0128,
    0x0129, 0x012A, 0x012B, 0x012C, 0x012D, 0x012E, 0x012F, 0x0130, 0x0131, 0x0133, 0x0134, 0x0135,
    0x0136, 0x0137, 0x0138, 0x0139, 0x013B, 0x013C, 0x013D, 0x013E, 0x013F, 0x0140, 0x0142, 0x0143,
    0x0144, 0x0145, 0x0146, 0x0147, 0x0148, 0x0149, 0x014A, 0x014B, 0x014C, 0x014D, 0x014E, 0x0150,
    0x0159, 0x015A, 0x015C, 0x015D, 0x015E, 0x015F, 0x0160, 0x0161, 0x0162, 0x0163, 0x0164, 0x0165,
    0x0166, 0x0167, 0x0168, 0x0169, 0x016A, 0x016B, 0x016D, 0x016E, 0x016F, 0x0170, 0x0171, 0x0172,
    0x0173, 0x0174, 0x0175, 0x0176, 0x0178, 0x0179, 0x017B, 0x017C, 0x017D, 0x017E, 0x017F, 0x0180,
    0x0183, 0x0185, 0x0187, 0x0188, 0x0189, 0x018A, 0x018B, 0x018C, 0x018D, 0x018F, 0x0190, 0x0191,
    0x0192, 0x0194, 0x0195, 0x0196, 0x0197, 0x0198, 0x0199, 0x019A, 0x019B, 0x019C, 0x019D, 0x019E,
    0x01A1, 0x01A4, 0x01A6, 0x01A7, 0x01A8, 0x01A9, 0x01AA, 0x01AC, 0x01AD, 0x01AE, 0x01AF, 0x01B0,
    0x01B1, 0x01B2, 0x01B3, 0x01B4, 0x01B5, 0x01B6, 0x01B8, 0x01B9, 0x01BA, 0x01BC, 0x01BE, 0x01BF,
    0x01C0, 0x01C2, 0x01C3, 0x01C4, 0x01C5, 0x01C7, 0x01C9, 0x01CD, 0x01CE, 0x01CF, 0x01D0, 0x01D2,
    0x01D3, 0x01D4, 0x01D5, 0x01D7, 0x01DA, 0x01DB, 0x01DC, 0x01DD, 0x01DE, 0x01DF, 0x01E0, 0x01E1,
    0x01E3, 0x01E5, 0x01E6, 0x01E8, 0x01E9, 0x01EA, 0x01EB, 0x01ED, 0x01EF, 0x01F0, 0x01F2, 0x01F7,
    0x01F8, 0x01F9, 0x01FA, 0x01FB, 0x01FC, 0x01FD, 0x01FE, 0x01FF, 0x0200, 0x0201, 0x0202, 0x0203,
    0x0204, 0x0205, 0x0206, 0x0207, 0x0208, 0x0209, 0x020A, 0x020B, 0x020C, 0x020D, 0x020E, 0x020F,
    0x0210, 0x0211, 0x0212, 0x0000,
};
static s16 lbl_2_data_1FD84[0xE8] = {
    0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0005, 0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0009,
    0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0002, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0001,
    0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002,
    0x0002, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0002, 0x0002, 0x0001, 0x0001,
    0x0002, 0x0001, 0x0001, 0x0001, 0x0002, 0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001,
    0x0001, 0x0001, 0x0002, 0x0003, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0001, 0x0002, 0x0005, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x0000,
};
static s16 lbl_2_data_1FF54[12] = {
    0x0000, 0x001A, 0x0034, 0x006A, 0x008C, 0x0091, 0x00C1, 0x00C3, 0x00C4, 0x00D2, 0x00D5, 0x0000,
};
static char lbl_2_data_1FF6C[12][2] = {
    "A", "K", "S", "T", "N", "H", "M", "Y", "R", "W", "D", "",
};
AramEntry0A58 lbl_2_data_1FF84 = { {
    0x0000040B, 0x4000A820, 0x18ED3800, 0x00003758,
} };
AramEntry0A58 lbl_2_data_1FF94[2] = {
    { { 0x00000000, 0x00006526, 0x08EAE000, 0x00006528 } },
    { { 0x0000040B, 0x40036CD8, 0x1945F800, 0x00023828 } },
};
u32 lbl_2_data_1FFB4[0x188] = {
    0x00000013, 0x00000000, 0x00000000, 0xFFFFFF00, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000123, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x001400FF, 0x01000000, 0x00000000, 0x00010000,
    0x00000018, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x001100FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0000000D, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x001300FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000011, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000800FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0000001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0000001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0000001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0000001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0000001A, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000012, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000600FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000010, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000600FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0000001B, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000600FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0000001B, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000600FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0000001D, 0x42C80000, 0x42480000, 0xFFFFFFFF, 0x000600FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000014, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000500FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000017, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000600FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000013, 0x00000000, 0x00000000, 0xFFFFFF00, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000016, 0x00000000, 0x00000000, 0xFFFFFF00, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0000001C, 0x00000000, 0x00000000, 0xFFFFFF00, 0x000600FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000019, 0x00000000, 0x00000000, 0xFFFFFF00, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000015, 0x00000000, 0x00000000, 0xFFFFFF00, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000F, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000F, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000F, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x0001000E, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000007, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x000700FF, 0x0A000000, 0x00000000, 0x00010000,
    0x00000006, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0007002B, 0x0A000000, 0x00000000, 0x00010000,
    0x00000008, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0007002B, 0x0A000000, 0x00000000, 0x00010000,
    0x00000009, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0007002D, 0x0A000000, 0x00000000, 0x00010000,
    0x00000009, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x0007002D, 0x0A000000, 0x00000000, 0x00010001,
    0x00030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
static MenuEntry0A58 lbl_2_data_205D4[43] = {
    { fn_2_58510, 0x0000, 0x0000, 0x0000, 0x001B, 0x0000, 0x0000 },
    { fn_2_58470, 0x0001, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000 },
    { fn_2_58328, 0x0002, 0x0000, 0x0000, 0x0002, 0x0000, 0x0000 },
    { fn_2_581E0, 0x0003, 0x0000, 0x0000, 0x0003, 0x0000, 0x0000 },
    { fn_2_58098, 0x0004, 0x0000, 0x0003, 0x0004, 0x0000, 0x0000 },
    { fn_2_57BF8, 0x0005, 0x0000, 0x0003, 0x0005, 0x0000, 0x0000 },
    { fn_2_57BF8, 0x0006, 0x0001, 0x0003, 0x0006, 0x0000, 0x0000 },
    { fn_2_57BF8, 0x0007, 0x0002, 0x0003, 0x0007, 0x0000, 0x0000 },
    { fn_2_57BF8, 0x0008, 0x0003, 0x0003, 0x0008, 0x0000, 0x0000 },
    { fn_2_57BF8, 0x0009, 0x0004, 0x0003, 0x0009, 0x0000, 0x0000 },
    { fn_2_57F50, 0x000A, 0x0000, 0x0002, 0x000A, 0x0000, 0x0000 },
    { fn_2_579B4, 0x000B, 0x0000, 0x0003, 0x000B, 0x0000, 0x0000 },
    { fn_2_5786C, 0x000C, 0x0000, 0x0003, 0x000C, 0x0000, 0x0000 },
    { fn_2_57724, 0x000D, 0x0001, 0x0003, 0x000D, 0x0000, 0x0000 },
    { fn_2_5754C, 0x000E, 0x0000, 0x0005, 0x000E, 0x0000, 0x0000 },
    { fn_2_57294, 0x000F, 0x0000, 0x0000, 0x000F, 0x0000, 0x0000 },
    { fn_2_57294, 0x0010, 0x0001, 0x0000, 0x0010, 0x0000, 0x0000 },
    { fn_2_57294, 0x0011, 0x0002, 0x0000, 0x0011, 0x0000, 0x0000 },
    { fn_2_57294, 0x0012, 0x0003, 0x0000, 0x0012, 0x0000, 0x0000 },
    { fn_2_57294, 0x0013, 0x0004, 0x0000, 0x0013, 0x0000, 0x0000 },
    { fn_2_57294, 0x0014, 0x0005, 0x0000, 0x0014, 0x0000, 0x0000 },
    { fn_2_57294, 0x0015, 0x0006, 0x0000, 0x0015, 0x0000, 0x0000 },
    { fn_2_57294, 0x0016, 0x0007, 0x0000, 0x0016, 0x0000, 0x0000 },
    { fn_2_57294, 0x0017, 0x0008, 0x0000, 0x0017, 0x0000, 0x0000 },
    { fn_2_57294, 0x0018, 0x0009, 0x0000, 0x0018, 0x0000, 0x0000 },
    { fn_2_57294, 0x0019, 0x000A, 0x0000, 0x0019, 0x0000, 0x0000 },
    { fn_2_570E4, 0x001A, 0x0000, 0x0004, 0x001A, 0x0000, 0x0000 },
    { fn_2_56E8C, 0x001B, 0x0000, 0x0002, 0x0020, 0x0006, 0x0000 },
    { fn_2_56E8C, 0x001C, 0x0001, 0x0002, 0x0021, 0x0007, 0x0000 },
    { fn_2_56C34, 0x001D, 0x0000, 0x0002, 0x0022, 0x0000, 0x0000 },
    { fn_2_56C34, 0x001E, 0x0001, 0x0002, 0x0023, 0x0001, 0x0000 },
    { fn_2_5699C, 0x001F, 0x0000, 0x0003, 0x0024, 0x0002, 0x0000 },
    { fn_2_56688, 0x0020, 0x0000, 0x0003, 0x0025, 0x0000, 0x0000 },
    { fn_2_56688, 0x0021, 0x0001, 0x0003, 0x0026, 0x0001, 0x0000 },
    { fn_2_56688, 0x0022, 0x0002, 0x0003, 0x0027, 0x0002, 0x0000 },
    { fn_2_56688, 0x0023, 0x0003, 0x0003, 0x0028, 0x0003, 0x0000 },
    { fn_2_56688, 0x0024, 0x0004, 0x0003, 0x0029, 0x0004, 0x0000 },
    { fn_2_563C0, 0x0025, 0x0000, 0x0003, 0x002A, 0x0008, 0x0000 },
    { fn_2_56160, 0x0026, 0x0000, 0x0006, 0x002B, 0x0000, 0x0000 },
    { fn_2_55FD8, 0x0027, 0x0000, 0x0006, 0x002C, 0x0000, 0x0000 },
    { fn_2_55DD8, 0x0028, 0x0000, 0x0006, 0x002D, 0x0000, 0x0000 },
    { fn_2_55C5C, 0x0029, 0x0000, 0x0006, 0x002E, 0x0000, 0x0000 },
    { fn_2_55AD4, 0x002A, 0x0000, 0x0006, 0x002F, 0x0000, 0x0000 },
};

// Nothing reads it; it fills the unit's .bss range after lbl_2_bss_9E10
static u8 lbl_2_bss_9E14[0x354];
s8 lbl_2_bss_9E10;

// .text:0x00058510 size:0x2C
void fn_2_58510(MenuTask0A58* task, MenuItem0A58* item) {
    lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
}

// .text:0x00058470 size:0xA0
void fn_2_58470(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        item->_04 = 0x26;
        break;
    case 2:
        item->_04 = 0x25;
        break;
    case 5:
    case 8:
    case 1:
    case 0x24:
    case 0x25:
        break;
    }
}

// .text:0x00058328 size:0x148
void fn_2_58328(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
        item->_04 = 0x26;
        break;
    case 8:
    case 1:
    case 0x24:
    case 0x25:
        break;
    }
}

// .text:0x000581E0 size:0x148
void fn_2_581E0(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
        item->_04 = 0x26;
        break;
    case 8:
    case 1:
    case 0x24:
    case 0x25:
        break;
    }
}

// .text:0x00058098 size:0x148
void fn_2_58098(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
        item->_04 = 0x26;
        break;
    case 8:
    case 1:
    case 0x24:
    case 0x25:
        break;
    }
}

// .text:0x00057F50 size:0x148
void fn_2_57F50(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
        item->_04 = 0x26;
        break;
    case 8:
    case 1:
    case 0x24:
    case 0x25:
        break;
    }
}

// .text:0x00057BF8 size:0x358
void fn_2_57BF8(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0;
        fn_80036134(task, 0x1E, item->_0A, item->_0A + 5);
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        item->_04 = 3;
        break;
    case 3:
        if (lbl_2_bss_1A824C->_1976FA == item->_0A) {
            if ((lbl_80371C30[task->_14 + item->_0E]._00->_5C >> 16) >= 0x14) {
                lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0x140000;
                lbl_80371C30[task->_14 + item->_0E]._00->_68 = 0;
                item->_04 = 0x25;
            }
        } else {
            if ((lbl_80371C30[task->_14 + item->_0E]._00->_5C >> 16) >= 0xA) {
                lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0xA0000;
                lbl_80371C30[task->_14 + item->_0E]._00->_68 = 0;
                item->_04 = 0x25;
            }
        }
        break;
    case 0x25:
        if (lbl_2_bss_1A824C->_1976FA == item->_0A) {
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
            if ((lbl_80371C30[task->_14 + item->_0E]._00->_5C >> 16) >= 0x14) {
                lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0x140000;
            }
        } else {
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
            if ((lbl_80371C30[task->_14 + item->_0E]._00->_5C >> 16) <= 0xA) {
                lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0xA0000;
            }
        }
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
        item->_04 = 6;
        break;
    case 6:
        if ((lbl_80371C30[task->_14 + item->_0E]._00->_5C >> 16) == 0) {
            lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0;
        }
        break;
    case 1:
    case 4:
        break;
    }
}

// .text:0x000579B4 size:0x244
void fn_2_579B4(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        if (lbl_2_data_1FD84[lbl_2_bss_1A824C->_1976FA + lbl_2_bss_1A824C->_1976FE] >= 2) {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        } else {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        }
        item->_04 = 0x25;
        break;
    case 0x25:
        if (lbl_2_data_1FD84[lbl_2_bss_1A824C->_1976FA + lbl_2_bss_1A824C->_1976FE] >= 2) {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        } else {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        }
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 1:
        break;
    }
}

// .text:0x0005786C size:0x148
void fn_2_5786C(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
        item->_04 = 0x26;
        break;
    case 8:
    case 1:
    case 0x24:
    case 0x25:
        break;
    }
}

// .text:0x00057724 size:0x148
void fn_2_57724(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
        item->_04 = 0x26;
        break;
    case 8:
    case 1:
    case 0x24:
    case 0x25:
        break;
    }
}

// .text:0x0005754C size:0x1D8
void fn_2_5754C(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        item->_04 = 0x26;
        break;
    case 2:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        fn_80036134(task, 0x1D, lbl_2_bss_1A824C->_1976FA, 0xE);
        lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0;
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        item->_04 = 0x25;
        break;
    case 0x25:
        fn_80036134(task, 0x1D, lbl_2_bss_1A824C->_1976FA, 0xE);
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 4:
    case 1:
        break;
    }
}

// .text:0x00057294 size:0x2B8
void fn_2_57294(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        fn_80036134(task, 0x1B, item->_0A, item->_0A + 0xF);
        lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0;
        fn_800363D8(task, item->_0E, 1, 0x15, item->_0A);
        item->_06 = item->_0A;
        item->_04 = 0x26;
        break;
    case 2:
        if (item->_06-- <= 0) {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
            item->_04 = 3;
        }
        break;
    case 3:
        if ((lbl_80371C30[task->_14 + item->_0E]._00->_5C >> 16) >= 5) {
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 0;
            item->_04 = 0x25;
        }
        break;
    case 0x25:
        if (lbl_2_bss_1A824C->_1976F4 == item->_0A) {
            if ((lbl_80371C30[task->_14 + item->_0E]._00->_5C >> 16) >= 0xF) {
                lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0xF0000;
            } else {
                lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
            }
        } else {
            if ((lbl_80371C30[task->_14 + item->_0E]._00->_5C >> 16) <= 5) {
                lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0x50000;
            } else {
                lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
            }
        }
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0;
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
        item->_04 = 0x26;
        break;
    case 1:
    case 4:
        break;
    }
}

// .text:0x000570E4 size:0x1B0
void fn_2_570E4(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
        lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0;
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        fn_80036134(task, 0x1C, lbl_2_bss_1A824C->_1976F4, 0x1A);
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        item->_04 = 0x25;
        break;
    case 0x25:
        fn_80036134(task, 0x1C, lbl_2_bss_1A824C->_1976F4, 0x1A);
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 1:
        break;
    }
}

// .text:0x00056E8C size:0x258
void fn_2_56E8C(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_12 = 0;
        item->_14 = fn_8000F988(task, item->_0E, item->_10, 2, 0x215, 0);
        item->_04 = 0x26;
        break;
    case 2:
        fn_8000FE08(item->_14, 2, item->_0A + 0x215);
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        item->_04 = 3;
        break;
    case 3:
        item->_12 += (0xFF - item->_12) / 4;
        item->_12++;
        if (item->_12 > 0xFF) {
            item->_12 = 0xFF;
        }
        if (item->_12 >= 0xFF) {
            item->_04 = 0x25;
        }
        break;
    case 0x25:
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 6;
        break;
    case 6:
        item->_12 += -item->_12 / 4;
        item->_12--;
        if (item->_12 < 0) {
            item->_12 = 0;
        }
        break;
    case 1:
    case 4:
        break;
    }
    lbl_80366B18._000[item->_14]._2F = 1;
    lbl_80371C30[task->_14 + item->_0E]._00->_58 = item->_12 | (lbl_80371C30[task->_14 + item->_0E]._00->_58 & 0xFFFFFF00);
}

// .text:0x00056C34 size:0x258
void fn_2_56C34(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_12 = 0;
        item->_14 = fn_8000F988(task, item->_0E, item->_10, 2, 0x213, 0);
        item->_04 = 0x26;
        break;
    case 2:
        fn_8000FE08(item->_14, 2, item->_0A + 0x213);
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        item->_04 = 3;
        break;
    case 3:
        item->_12 += (0xFF - item->_12) / 4;
        item->_12++;
        if (item->_12 > 0xFF) {
            item->_12 = 0xFF;
        }
        if (item->_12 >= 0xFF) {
            item->_04 = 0x25;
        }
        break;
    case 0x25:
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 6;
        break;
    case 6:
        item->_12 += -item->_12 / 4;
        item->_12--;
        if (item->_12 < 0) {
            item->_12 = 0;
        }
        break;
    case 1:
    case 4:
        break;
    }
    lbl_80366B18._000[item->_14]._2F = 1;
    lbl_80371C30[task->_14 + item->_0E]._00->_58 = item->_12 | (lbl_80371C30[task->_14 + item->_0E]._00->_58 & 0xFFFFFF00);
}

// .text:0x0005699C size:0x298
void fn_2_5699C(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);
    s16 n;

    if (state != -1) {
        item->_04 = state;
    }
    n = lbl_2_bss_1A824C->_1976FE + lbl_2_bss_1A824C->_1976FA;
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_12 = 0;
        item->_14 = fn_8000F988(task, item->_0E, item->_10, 2, 0, 0);
        item->_04 = 0x26;
        break;
    case 2:
        fn_8000FE08(item->_14, 2, n);
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        fn_8000FE08(item->_14, 2, n);
        item->_04 = 3;
        break;
    case 3:
        item->_12 += (0xFF - item->_12) / 4;
        item->_12++;
        if (item->_12 > 0xFF) {
            item->_12 = 0xFF;
        }
        if (item->_12 >= 0xFF) {
            item->_04 = 0x25;
        }
        break;
    case 0x25:
        fn_8000FE08(item->_14, 2, n);
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 6;
        break;
    case 6:
        item->_12 += -item->_12 / 4;
        item->_12--;
        if (item->_12 < 0) {
            item->_12 = 0;
        }
        break;
    case 1:
    case 4:
        break;
    }
    lbl_80366B18._000[item->_14]._2F = 1;
    lbl_80371C30[task->_14 + item->_0E]._00->_58 = item->_12 | (lbl_80371C30[task->_14 + item->_0E]._00->_58 & 0xFFFFFF00);
}

// .text:0x00056688 size:0x314
void fn_2_56688(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);
    s16 n;
    u32 color;

    if (state != -1) {
        item->_04 = state;
    }
    n = (lbl_2_bss_1A824C->_1976FE + item->_0A) % lbl_2_bss_1A824C->_19772E;
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_12 = 0;
        item->_14 = fn_8000F988(task, item->_0E, item->_10, 2, 0, 1);
        item->_04 = 0x26;
        break;
    case 2:
        fn_8000FE08(item->_14, 2, n);
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        fn_8000FE08(item->_14, 2, n);
        item->_04 = 3;
        break;
    case 3:
        item->_12 += (0xFF - item->_12) / 4;
        item->_12++;
        if (item->_12 > 0xFF) {
            item->_12 = 0xFF;
        }
        if (item->_12 >= 0xFF) {
            item->_04 = 0x25;
        }
        break;
    case 0x25:
        fn_8000FE08(item->_14, 2, n);
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 6;
        break;
    case 6:
        item->_12 += -item->_12 / 4;
        item->_12--;
        if (item->_12 < 0) {
            item->_12 = 0;
        }
        break;
    case 1:
    case 4:
        break;
    }
    if (item->_0A == lbl_2_bss_1A824C->_1976FA) {
        color = fn_80036214(task, 0x25, 0, 1);
    } else {
        color = fn_80036214(task, 0x26, 0, 0);
    }
    lbl_80371C30[task->_14 + item->_0E]._00->_58 = (lbl_80371C30[task->_14 + item->_0E]._00->_58 & 0xFF) | (color & 0xFFFFFF00);
    lbl_80366B18._000[item->_14]._2F = 0;
    lbl_80371C30[task->_14 + item->_0E]._00->_58 = item->_12 | (lbl_80371C30[task->_14 + item->_0E]._00->_58 & 0xFFFFFF00);
}

// .text:0x000563C0 size:0x2C8
void fn_2_563C0(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);
    s16 n;

    if (state != -1) {
        item->_04 = state;
    }
    n = lbl_2_bss_1A824C->_197822 + lbl_2_data_1FBB4[lbl_2_bss_1A824C->_1976FE + lbl_2_bss_1A824C->_1976FA];
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_12 = 0;
        item->_14 = fn_8000F988(task, item->_0E, item->_10, 2, lbl_2_data_1FBB4[0], 0);
        item->_04 = 0x26;
        break;
    case 2:
        fn_8000FE08(item->_14, 2, n);
        lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        fn_8000FE08(item->_14, 2, n);
        item->_04 = 3;
        break;
    case 3:
        item->_12 += (0xFF - item->_12) / 4;
        item->_12++;
        if (item->_12 > 0xFF) {
            item->_12 = 0xFF;
        }
        if (item->_12 >= 0xFF) {
            item->_04 = 0x25;
        }
        break;
    case 0x25:
        fn_8000FE08(item->_14, 2, n);
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 6;
        break;
    case 6:
        item->_12 += -item->_12 / 4;
        item->_12--;
        if (item->_12 < 0) {
            item->_12 = 0;
        }
        break;
    case 1:
    case 4:
        break;
    }
    lbl_80366B18._000[item->_14]._2F = 0;
    lbl_80366B18._000[item->_14]._30 = 1;
    lbl_80371C30[task->_14 + item->_0E]._00->_58 = item->_12 | (lbl_80371C30[task->_14 + item->_0E]._00->_58 & 0xFFFFFF00);
}

// .text:0x00056160 size:0x260
void fn_2_56160(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
    case 8:
        if (lbl_2_data_1FD84[lbl_2_bss_1A824C->_1976FA + lbl_2_bss_1A824C->_1976FE] > 1) {
            lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0;
            lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        } else {
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
        }
        item->_04 = 0x25;
        break;
    case 5:
        if (lbl_2_data_1FD84[lbl_2_bss_1A824C->_1976FA + lbl_2_bss_1A824C->_1976FE] > 1) {
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
            item->_04 = 6;
        } else {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        }
        break;
    case 6:
        if ((lbl_80371C30[task->_14 + item->_0E]._00->_5C >> 16) == 0) {
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 0;
            item->_04 = 7;
        }
        break;
    case 7:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        break;
    case 0x25:
        break;
    }
}

// .text:0x00055FD8 size:0x188
void fn_2_55FD8(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
    case 8:
        if (lbl_2_data_1FD84[lbl_2_bss_1A824C->_1976FA + lbl_2_bss_1A824C->_1976FE] > 1) {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        } else {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
        }
        item->_04 = 0x25;
        break;
    case 5:
        item->_06 = 10;
        item->_04 = 6;
        break;
    case 6:
        if (item->_06-- <= 0) {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        }
        break;
    case 0x25:
        break;
    }
}

// .text:0x00055DD8 size:0x200
void fn_2_55DD8(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
    case 8:
    case 17:
        if (lbl_2_data_1FD84[lbl_2_bss_1A824C->_1976FA + lbl_2_bss_1A824C->_1976FE] > 1) {
            lbl_80371C30[task->_14 + item->_0E]._00->_5C = 0;
            lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        } else {
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 1;
        }
        item->_04 = 0x25;
        break;
    case 5:
        lbl_80371C30[task->_14 + item->_0E]._00->_68 = 4;
        item->_04 = 6;
        break;
    case 6:
        if ((lbl_80371C30[task->_14 + item->_0E]._00->_5C >> 16) == 0) {
            lbl_80371C30[task->_14 + item->_0E]._00->_68 = 0;
            item->_04 = 7;
        }
        break;
    case 7:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        break;
    case 0x25:
        break;
    }
}

// .text:0x00055C5C size:0x17C
void fn_2_55C5C(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);
    s16 n;

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
    case 8:
    case 17:
        n = lbl_2_data_1FD84[lbl_2_bss_1A824C->_1976FA + lbl_2_bss_1A824C->_1976FE];
        if (n > 1) {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
            lbl_80371C30[task->_14 + item->_0E]._00->_5C = (n - 1) << 16;
        }
        item->_04 = 0x25;
        break;
    case 5:
        item->_06 = 10;
        item->_04 = 6;
        break;
    case 6:
        if (item->_06-- <= 0) {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        }
        break;
    case 0x25:
        break;
    }
}

// .text:0x00055AD4 size:0x188
void fn_2_55AD4(MenuTask0A58* task, MenuItem0A58* item) {
    s16 state = fn_2_53BC8(item);

    if (state != -1) {
        item->_04 = state;
    }
    switch (item->_04) {
    case 0:
        lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        item->_04 = 0x26;
        break;
    case 2:
    case 8:
    case 17:
        if (lbl_2_data_1FD84[lbl_2_bss_1A824C->_1976FA + lbl_2_bss_1A824C->_1976FE] > 1) {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 |= 2;
            lbl_80371C30[task->_14 + item->_0E]._00->_5C = lbl_2_bss_1A824C->_197822 << 16;
        }
        item->_04 = 0x25;
        break;
    case 5:
        item->_06 = 10;
        item->_04 = 6;
        break;
    case 6:
        if (item->_06-- <= 0) {
            lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
        }
        break;
    case 0x25:
        break;
    }
}

// .text:0x00055A40 size:0x94
void fn_2_55A40(void) {
    lbl_2_bss_1A824C->_1972BC = 1;
    fn_2_4E7EC();
    fn_8001F228();
    fn_80021410();
    fn_800ACFB0(lbl_800EF808._14);
    fn_80035B50(10);
    if (lbl_80366B18._7A0 != NULL) {
        fn_800ACFB0(lbl_80366B18._7A0);
        lbl_80366B18._7A0 = NULL;
    }
    lbl_2_bss_1A823C->_34 = 0;
}

// .text:0x0005597C size:0xC4
s32 fn_2_5597C(void) {
    s32 result;
    s32 n = lbl_2_bss_1A824C->_1976FE + lbl_2_bss_1A824C->_1976FA;

    if (n < 0x1A) {
        result = 0;
    } else if (n < 0x34) {
        result = 1;
    } else if (n < 0x6A) {
        result = 2;
    } else if (n < 0x8C) {
        result = 3;
    } else if (n < 0x91) {
        result = 4;
    } else if (n < 0xC1) {
        result = 5;
    } else if (n < 0xC3) {
        result = 6;
    } else if (n < 0xC4) {
        result = 7;
    } else if (n < 0xD2) {
        result = 8;
    } else if (n < 0xD5) {
        result = 9;
    } else {
        result = 10;
    }
    return result;
}

// .text:0x00054BAC size:0x4
void fn_2_54BAC(void) {}

// .text:0x00054B38 size:0x74
void fn_2_54B38(void) {
    if (lbl_8036E548._307A == 2) {
        if (lbl_2_bss_1A8248->_44F2 != 4) {
            fn_2_68E68();
        }
        fn_2_47FF8();
        if (lbl_2_bss_1A8248->_44F2 != 4) {
            fn_2_47CFC();
        }
    }
    GXSetZCompLoc(GX_FALSE);
}

// .text:0x00054BB0 size:0xDCC
void fn_2_54BB0(void) {
    MenuSave0A58* save;
    Vec pos;
    MenuTask0A58* task = lbl_803CC1B8;
    MenuTask0A58* child;

    lbl_2_bss_1A824C = (void*)lbl_2_bss_1A8250;
    lbl_2_bss_1A8248 = (void*)starMissionCompletionTracker;
    lbl_2_bss_1A8244 = (void*)lbl_80361B20;
    lbl_2_bss_1A823C = (void*)lbl_800E877C;
    lbl_2_bss_1A8234 = (void*)lbl_2_bss_1A8250;
    lbl_2_bss_1A8230 = (void*)(lbl_2_bss_1A8250 + 0x162998);
    save = &lbl_8034E9A0;
    if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._0C == 12) {
        lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 |= lbl_803C77B8[lbl_2_bss_1A824C->_197863]._00;
    }
    switch (lbl_803CBBCC->_4) {
    case 0:
        memset(lbl_2_bss_1A8250, 0, sizeof(lbl_2_bss_1A8250));
        fn_2_54474();
        lbl_2_bss_1A824C->_197848 = 1;
        fn_2_94854(0);
        fn_2_9461C(-1);
        fn_2_94604(0);
        fn_2_93C64();
        g_d_GameSettings.StadiumID = 0;
        lbl_2_bss_1A824C->_197863 = save->_46F8;
        child = fn_800B0A5C_insertQueue(fn_2_549B4, 2);
        child->_28 = 0;
        task->_10 = 0;
        fn_8000F4B8(0, -1, -1, -1);
        lbl_803CBBCC->_4 = 1;
        break;
    case 1:
        if (task->_10 == 1) {
            lbl_803CBBCC->_4 = 2;
        }
        break;
    case 2:
        fn_800B0A5C_insertQueue(fn_8006295C, 2);
        changeScene(1, 6);
        fn_2_6ACF4();
        fn_800B0A5C_insertQueue(fn_2_71F60, 2);
        pos.z = 0.0f;
        pos.y = 0.0f;
        pos.x = 0.0f;
        fn_2_6AB3C(0, &pos, 0.0f);
        fn_2_72054(0, 0);
        lbl_2_bss_1A8234->_162604[13][0] = 0;
        fn_2_54890();
        lbl_2_bss_1A824C->_1976F6 = 0;
        lbl_2_bss_1A824C->_1976F4 = 0;
        lbl_803CBBCC->_4 = 3;
        break;
    case 3:
        if (lbl_8037169C._12 != 0) {
            lbl_2_bss_1A8234->_162604[1][0] = 1;
            lbl_2_bss_1A8234->_162604[1][1] = 1;
            lbl_2_bss_1A8234->_162604[1][2] = 1;
            lbl_2_bss_1A8234->_162600 = 16;
            lbl_803CBBCC->_4 = 4;
        }
        break;
    case 4:
        if (lbl_2_bss_1A8234->_162600-- == 0) {
            lbl_2_bss_1A8234->_162604[1][4] = 1;
            lbl_803CBBCC->_4 = 5;
        }
        break;
    case 5:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 == 1) {
            lbl_2_bss_1A824C->_1976F6 = lbl_2_bss_1A824C->_1976F4;
            lbl_2_bss_1A824C->_1976F4 = (lbl_2_bss_1A824C->_1976F4 + 10) % 11;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 == 2) {
            lbl_2_bss_1A824C->_1976F6 = lbl_2_bss_1A824C->_1976F4;
            lbl_2_bss_1A824C->_1976F4 = (lbl_2_bss_1A824C->_1976F4 + 1) % 11;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
        }
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
            lbl_803CBBCC->_4 = 6;
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) {
            lbl_803CBBCC->_4 = 8;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        }
        break;
    case 6:
        lbl_2_bss_1A8234->_162604[8][1] = 1;
        lbl_2_bss_1A8234->_162604[8][2] = 1;
        lbl_803CBBCC->_4 = 7;
        lbl_2_bss_1A8234->_162600 = 16;
        break;
    case 7:
        if (lbl_2_bss_1A8234->_162600-- == 0) {
            lbl_803CBBCC->_4 = 9;
        }
        break;
    case 8:
        lbl_2_bss_1A8234->_162600 = 20;
        lbl_2_bss_1A8234->_162604[8][0] = 1;
        lbl_2_bss_1A8234->_162604[8][1] = 1;
        lbl_2_bss_1A8234->_162604[8][2] = 1;
        lbl_2_bss_1A8234->_162604[8][4] = 1;
        lbl_8034E978._05 = 1;
        lbl_803CBBCC->_4 = 16;
        break;
    case 9:
        fn_2_72054(0, 17);
        lbl_2_bss_1A824C->_19772E = 231;
        lbl_2_bss_1A824C->_1976FE = lbl_2_bss_1A824C->_197700 = lbl_2_data_1FF54[lbl_2_bss_1A824C->_1976F4];
        lbl_2_bss_1A824C->_1976FA = lbl_2_bss_1A824C->_1976FC = 0;
        lbl_2_bss_1A824C->_197822 = 0;
        lbl_2_bss_1A8234->_162604[1][1] = 1;
        lbl_2_bss_1A8234->_162604[1][3] = 1;
        lbl_2_bss_1A8234->_162604[1][6] = 1;
        lbl_2_bss_1A8234->_162600 = 16;
        lbl_803CBBCC->_4 = 10;
        break;
    case 10:
        if (lbl_2_bss_1A8234->_162600-- == 0) {
            lbl_2_bss_1A8234->_162604[1][5] = 1;
            lbl_803CBBCC->_4 = 12;
        }
        break;
    case 12:
        if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 == 1) {
            lbl_2_bss_1A824C->_1976F6 = lbl_2_bss_1A824C->_1976F4;
            lbl_2_bss_1A824C->_1976F4 = (lbl_2_bss_1A824C->_1976F4 + 10) % 11;
            lbl_2_bss_1A824C->_197700 = lbl_2_bss_1A824C->_1976FE;
            lbl_2_bss_1A824C->_1976FC = lbl_2_bss_1A824C->_1976FA;
            lbl_2_bss_1A824C->_1976FE = lbl_2_data_1FF54[lbl_2_bss_1A824C->_1976F4];
            lbl_2_bss_1A824C->_1976FA = 0;
            lbl_2_bss_1A824C->_197822 = 0;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            lbl_2_bss_1A8234->_162604[3][6] = 1;
            lbl_803CBBCC->_4 = 15;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 == 2) {
            lbl_2_bss_1A824C->_1976F6 = lbl_2_bss_1A824C->_1976F4;
            lbl_2_bss_1A824C->_1976F4 = (lbl_2_bss_1A824C->_1976F4 + 1) % 11;
            lbl_2_bss_1A824C->_197700 = lbl_2_bss_1A824C->_1976FE;
            lbl_2_bss_1A824C->_1976FC = lbl_2_bss_1A824C->_1976FA;
            lbl_2_bss_1A824C->_1976FE = lbl_2_data_1FF54[lbl_2_bss_1A824C->_1976F4];
            lbl_2_bss_1A824C->_1976FA = 0;
            lbl_2_bss_1A824C->_197822 = 0;
            sndFXStartEx(0x1B7, lbl_800EFBA4[0], 0x3F, 0);
            lbl_2_bss_1A8234->_162604[3][6] = 1;
            lbl_803CBBCC->_4 = 15;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 == 8 || lbl_803C77B8[lbl_2_bss_1A824C->_197863]._04 == 4) {
            lbl_2_bss_1A824C->_197700 = lbl_2_bss_1A824C->_1976FE;
            lbl_2_bss_1A824C->_1976FC = lbl_2_bss_1A824C->_1976FA;
            fn_2_46D94(&lbl_2_bss_1A824C->_1976FA, &lbl_2_bss_1A824C->_1976FE, lbl_2_bss_1A824C->_19772E, 5, 9);
            lbl_2_bss_1A824C->_1976F4 = fn_2_5597C();
            lbl_2_bss_1A824C->_197822 = 0;
            lbl_2_bss_1A8234->_162604[3][6] = 1;
            lbl_803CBBCC->_4 = 15;
        } else if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) &&
                   lbl_2_data_1FD84[lbl_2_bss_1A824C->_1976FA + lbl_2_bss_1A824C->_1976FE] >= 2) {
            lbl_2_bss_1A824C->_197822 = (lbl_2_bss_1A824C->_197822 + 1) %
                                        lbl_2_data_1FD84[lbl_2_bss_1A824C->_1976FA + lbl_2_bss_1A824C->_1976FE];
            sndFXStartEx(0x1B8, lbl_800EFBA4[1], 0x3F, 0);
            lbl_2_bss_1A8234->_162604[6][6] = 1;
        } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) {
            lbl_803CBBCC->_4 = 13;
            sndFXStartEx(0x1B9, lbl_800EFBA4[2], 0x3F, 0);
        }
        break;
    case 13:
        lbl_2_bss_1A8234->_162604[8][1] = 1;
        lbl_2_bss_1A8234->_162604[8][3] = 1;
        lbl_2_bss_1A8234->_162604[8][5] = 1;
        lbl_2_bss_1A8234->_162604[8][6] = 1;
        fn_2_72054(0, 18);
        lbl_2_bss_1A8234->_162600 = 16;
        lbl_803CBBCC->_4 = 14;
        break;
    case 14:
        if (lbl_2_bss_1A8234->_162600-- == 0) {
            lbl_2_bss_1A8234->_162604[1][1] = 1;
            lbl_2_bss_1A8234->_162604[1][2] = 1;
            lbl_2_bss_1A8234->_162600 = 16;
            lbl_803CBBCC->_4 = 4;
        }
        break;
    case 15:
        lbl_803CBBCC->_4 = 12;
        break;
    case 16:
        if (lbl_2_bss_1A8234->_162600-- == 0) {
            fn_80062948();
            changeScene(3, 6);
            lbl_803CBBCC->_4 = 17;
        }
        break;
    case 17:
        if (lbl_8037169C._13 != 0) {
            lbl_8036E548._307A = 0;
            lbl_2_bss_1A8234->_162604[13][0] = 1;
            lbl_2_bss_1A8230->_32A04[13][0] = 1;
            lbl_803CBBCC->_4 = 18;
        }
        break;
    case 18:
        fn_2_55A40();
        fn_2_11A0(5);
        break;
    case 19:
        child = fn_800B0A5C_insertQueue(fn_2_535B0, 2);
        child->_28 = 0;
        task->_10 = 0;
        lbl_803CBBCC->_4 = 20;
        break;
    case 20:
        if (task->_10 == 1) {
            lbl_803CBBCC->_4 = 12;
        }
        break;
    }
    fn_2_54B38();
}

// .text:0x000549B4 size:0x184
void fn_2_549B4(void) {
    MenuTask0A58* task = lbl_803CC1B8;
    MenuTask0A58* child;

    switch (task->_28) {
    case 0:
        lbl_80366B18._7A0 = ARAMTransfer(lbl_2_data_1FF94, 0, 1, 0);
        task->_28 = 1;
        break;
    case 1:
        if (lbl_803C6CF8._715 == 1) {
            fn_800111B4(lbl_80366B18._7A0);
            task->_28 = 2;
        }
        break;
    case 2:
        if (fn_80035838(&lbl_2_data_1FF84, 10) != 0) {
            task->_28 = 3;
        }
        break;
    case 3:
        task->_10 = 0;
        fn_800216F8(4, fn_800627C4);
        task->_28 = 4;
        break;
    case 4:
        if (task->_10 != 0) {
            task->_10 = 0;
            task->_28 = 5;
        }
        break;
    case 5:
        lbl_2_bss_1A824C->_197746 = 1;
        child = fn_800B0A5C_insertQueue(fn_2_8E8A4, 2);
        child->_28 = 0;
        child->_16 = 12;
        task->_10 = 0;
        task->_28 = 6;
        break;
    case 6:
        if (task->_10 == 1) {
            task->_0C->_10 = 1;
            fn_800B0A14_removeQueue();
            task->_28 = 0;
        }
        break;
    }
}

// .text:0x00054890 size:0x124
void fn_2_54890(void) {
    MenuTask0A58* task;

    lbl_8034E978._00 = 0x5C;
    lbl_8034E978._09 = lbl_8034E978._08;
    lbl_8034E978._08 = lbl_800FEF70[0x5C]._08;
    fn_800B0A5C_insertQueue(fn_80053FE8, 0);
    task = fn_800B0A5C_insertQueue(fn_2_5389C, 0);
    task->_1C = 0;
    task->_1E = 0;
    fn_2_54354(lbl_2_data_205D4, 43);
    lbl_2_bss_1A8234->_162604[0][0] = 1;
    lbl_2_bss_1A8234->_162604[0][1] = 1;
    lbl_2_bss_1A8234->_162604[0][2] = 1;
    lbl_2_bss_1A8234->_162604[0][3] = 1;
    lbl_2_bss_1A8234->_162604[0][6] = 1;
}

// .text:0x00054874 size:0x1C
void fn_2_54874(void) {
    lbl_2_bss_1A824C->_197754 = 0;
}

// .text:0x00054848 size:0x2C
void fn_2_54848(void) {
    lbl_2_bss_1A824C->_197754 = 1;
    lbl_2_bss_1A824C->_197752 = 10;
}

// .text:0x00054844 size:0x4
void fn_2_54844(void) {}

// .text:0x00054474 size:0x3D0
void fn_2_54474(void) {
    MenuItem0A58* item;
    s32 i;
    s32 j;

    for (i = 0; i < 0x46; i++) {
        for (j = 0; j < 0x360; j++) {
            item = &lbl_2_bss_1A8234->_000000[i][j];
            item->fn = NULL;
            item->_04 = 0;
            item->_06 = 0;
            item->_10 = 0;
            item->_08 = 0;
            item->_0A = 0;
            item->_0C = 0;
            item->_0E = 0;
            item->_12 = 0;
            item->_14 = 0;
        }
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 0x360; j++) {
            item = &lbl_2_bss_1A8230->_00000[i][j];
            item->fn = NULL;
            item->_04 = 0;
            item->_06 = 0;
            item->_10 = 0;
            item->_08 = 0;
            item->_0A = 0;
            item->_0C = 0;
            item->_0E = 0;
            item->_12 = 0;
            item->_14 = 0;
        }
    }
}

// .text:0x00054354 size:0x120
void fn_2_54354(MenuEntry0A58* entries, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        MenuItem0A58* item = &lbl_2_bss_1A8234->_000000[entries[i]._08][entries[i]._04];
        item->fn = entries[i].fn;
        item->_08 = entries[i]._04;
        item->_0A = entries[i]._06;
        item->_0C = entries[i]._08;
        item->_0E = entries[i]._0A;
        item->_10 = entries[i]._0C;
    }
}

// .text:0x00054234 size:0x120
void fn_2_54234(MenuEntry0A58* entries, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        MenuItem0A58* item = &lbl_2_bss_1A8230->_00000[entries[i]._08][entries[i]._04];
        item->fn = entries[i].fn;
        item->_08 = entries[i]._04;
        item->_0A = entries[i]._06;
        item->_0C = entries[i]._08;
        item->_0E = entries[i]._0A;
        item->_10 = entries[i]._0C;
    }
}

// .text:0x00054120 size:0x114
void fn_2_54120(void) {
    s32 i;

    for (i = 0; i < 0x46; i++) {
        lbl_2_bss_1A8234->_162604[0][i] = 0;
        lbl_2_bss_1A8234->_162604[1][i] = 0;
        lbl_2_bss_1A8234->_162604[2][i] = 0;
        lbl_2_bss_1A8234->_162604[3][i] = 0;
        lbl_2_bss_1A8234->_162604[4][i] = 0;
        lbl_2_bss_1A8234->_162604[5][i] = 0;
        lbl_2_bss_1A8234->_162604[6][i] = 0;
        lbl_2_bss_1A8234->_162604[7][i] = 0;
        lbl_2_bss_1A8234->_162604[8][i] = 0;
        lbl_2_bss_1A8234->_162604[9][i] = 0;
        lbl_2_bss_1A8234->_162604[10][i] = 0;
        lbl_2_bss_1A8234->_162604[11][i] = 0;
        lbl_2_bss_1A8234->_162604[12][i] = 0;
    }
}

// .text:0x0005400C size:0x114
void fn_2_5400C(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        lbl_2_bss_1A8230->_32A04[0][i] = 0;
        lbl_2_bss_1A8230->_32A04[1][i] = 0;
        lbl_2_bss_1A8230->_32A04[2][i] = 0;
        lbl_2_bss_1A8230->_32A04[3][i] = 0;
        lbl_2_bss_1A8230->_32A04[4][i] = 0;
        lbl_2_bss_1A8230->_32A04[5][i] = 0;
        lbl_2_bss_1A8230->_32A04[6][i] = 0;
        lbl_2_bss_1A8230->_32A04[7][i] = 0;
        lbl_2_bss_1A8230->_32A04[8][i] = 0;
        lbl_2_bss_1A8230->_32A04[9][i] = 0;
        lbl_2_bss_1A8230->_32A04[10][i] = 0;
        lbl_2_bss_1A8230->_32A04[11][i] = 0;
        lbl_2_bss_1A8230->_32A04[12][i] = 0;
    }
}

// .text:0x00053F88 size:0x84
void fn_2_53F88(MenuTask0A58* task) {
    s32 i;
    s32 j;

    for (i = 0; i < 0x46; i++) {
        for (j = 0; j < 0x360; j++) {
            MenuItem0A58* item = &lbl_2_bss_1A8234->_000000[i][j];
            if (item->fn != NULL) {
                item->fn(task, item);
            }
        }
    }
}

// .text:0x00053F04 size:0x84
void fn_2_53F04(MenuTask0A58* task) {
    s32 i;
    s32 j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 0x360; j++) {
            MenuItem0A58* item = &lbl_2_bss_1A8230->_00000[i][j];
            if (item->fn != NULL) {
                item->fn(task, item);
            }
        }
    }
}

// .text:0x00053DF8 size:0x10C
void fn_2_53DF8(MenuTask0A58* task) {
    MenuItem0A58* item;
    s32 i;
    s32 j;

    for (i = 0; i < 0x46; i++) {
        for (j = 0; j < 0x360; j++) {
            item = &lbl_2_bss_1A8234->_000000[i][j];
            if (item->fn != NULL) {
                lbl_80371C30[task->_14 + item->_0E]._00->_68 = 0;
                lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
            }
        }
    }
}

// .text:0x00053CEC size:0x10C
void fn_2_53CEC(MenuTask0A58* task) {
    MenuItem0A58* item;
    s32 i;
    s32 j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 0x360; j++) {
            item = &lbl_2_bss_1A8230->_00000[i][j];
            if (item->fn != NULL) {
                lbl_80371C30[task->_14 + item->_0E]._00->_68 = 0;
                lbl_80371C30[task->_14 + item->_0E]._00->_54 &= ~2;
            }
        }
    }
}

// .text:0x00053BC8 size:0x124
s16 fn_2_53BC8(MenuItem0A58* item) {
    s32 state = -1;

    if (lbl_2_bss_1A8234->_162604[0][item->_0C] != 0) {
        state = 0;
    } else if (lbl_2_bss_1A8234->_162604[1][item->_0C] != 0) {
        state = 2;
    } else if (lbl_2_bss_1A8234->_162604[8][item->_0C] != 0) {
        state = 5;
    } else if (lbl_2_bss_1A8234->_162604[2][item->_0C] != 0) {
        state = 23;
    } else if (lbl_2_bss_1A8234->_162604[3][item->_0C] != 0) {
        state = 8;
    } else if (lbl_2_bss_1A8234->_162604[4][item->_0C] != 0) {
        state = 11;
    } else if (lbl_2_bss_1A8234->_162604[5][item->_0C] != 0) {
        state = 14;
    } else if (lbl_2_bss_1A8234->_162604[6][item->_0C] != 0) {
        state = 17;
    } else if (lbl_2_bss_1A8234->_162604[7][item->_0C] != 0) {
        state = 20;
    } else if (lbl_2_bss_1A8234->_162604[9][item->_0C] != 0) {
        state = 24;
    } else if (lbl_2_bss_1A8234->_162604[10][item->_0C] != 0) {
        state = 27;
    } else if (lbl_2_bss_1A8234->_162604[11][item->_0C] != 0) {
        state = 30;
    } else if (lbl_2_bss_1A8234->_162604[12][item->_0C] != 0) {
        state = 33;
    }
    return state;
}

// .text:0x00053AA4 size:0x124
s16 fn_2_53AA4(MenuItem0A58* item) {
    s32 state = -1;

    if (lbl_2_bss_1A8230->_32A04[0][item->_0C] != 0) {
        state = 0;
    } else if (lbl_2_bss_1A8230->_32A04[1][item->_0C] != 0) {
        state = 2;
    } else if (lbl_2_bss_1A8230->_32A04[8][item->_0C] != 0) {
        state = 5;
    } else if (lbl_2_bss_1A8230->_32A04[2][item->_0C] != 0) {
        state = 23;
    } else if (lbl_2_bss_1A8230->_32A04[3][item->_0C] != 0) {
        state = 8;
    } else if (lbl_2_bss_1A8230->_32A04[4][item->_0C] != 0) {
        state = 11;
    } else if (lbl_2_bss_1A8230->_32A04[5][item->_0C] != 0) {
        state = 14;
    } else if (lbl_2_bss_1A8230->_32A04[6][item->_0C] != 0) {
        state = 17;
    } else if (lbl_2_bss_1A8230->_32A04[7][item->_0C] != 0) {
        state = 20;
    } else if (lbl_2_bss_1A8230->_32A04[9][item->_0C] != 0) {
        state = 24;
    } else if (lbl_2_bss_1A8230->_32A04[10][item->_0C] != 0) {
        state = 27;
    } else if (lbl_2_bss_1A8230->_32A04[11][item->_0C] != 0) {
        state = 30;
    } else if (lbl_2_bss_1A8230->_32A04[12][item->_0C] != 0) {
        state = 33;
    }
    return state;
}

// .text:0x0005389C size:0x208
void fn_2_5389C(void) {
    MenuTask0A58* task = lbl_803CC1B8;

    switch (task->_1C) {
    case 0:
        fn_2_4E878(task, lbl_2_data_1FFB4);
        task->_1C = 1;
        task->_18 = 0;
        break;
    case 1:
        break;
    }
    fn_2_53F88(task);
    fn_2_54120();
    if (lbl_2_bss_1A8234->_162604[13][0] != 0) {
        fn_8000F8F4(task);
        fn_8000FE54();
        fn_2_4E858(task);
        fn_800B0A14_removeQueue();
        task->_1C = 0;
        task->_1E = 0;
        lbl_2_bss_1A8234->_162604[13][0] = 0;
    }
}

// .text:0x000535B0 size:0x2EC
void fn_2_535B0(void) {
    MenuTask0A58* task = lbl_803CC1B8;
    s32 i;

    switch (task->_28) {
    case 0:
        lbl_2_bss_1A824C->_1976A4 = 0;
        lbl_2_bss_1A824C->_1976A0 = 0;
        task->_28 = 1;
        break;
    case 1:
        fn_2_1FFC4(2);
        for (i = 0; i < 2; i++) {
            fn_2_1FF10(i);
            switch (i) {
            case 0:
                if (lbl_2_bss_1A824C->_1976A0 == i && ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) || lbl_803C77B8[0]._13 > 50)) {
                    task->_28 = 3;
                }
                break;
            case 1:
                if (lbl_2_bss_1A824C->_1976A0 == i && (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x102)) {
                    lbl_2_bss_1A824C->_19784A = 1;
                    lbl_2_bss_1A824C->_197846 = 0;
                    lbl_2_bss_1A824C->_197845 = 1;
                    lbl_2_bss_9E10 = 1;
                    task->_28 = 2;
                }
                break;
            }
        }
        if ((lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) || lbl_803C77B8[0]._13 > 50) {
            task->_28 = 3;
        }
        break;
    case 2:
        fn_2_1FF14(1);
        for (i = 0; i < 1; i++) {
            fn_2_1FF0C(i);
            switch (i) {
            case 0:
                if (lbl_2_bss_1A824C->_1976A4 == i) {
                    if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x200) {
                        lbl_2_bss_1A824C->_19784A = 0;
                        lbl_2_bss_1A824C->_197846 = 0;
                        lbl_2_bss_1A824C->_1976A4 = 0;
                        lbl_2_bss_1A824C->_197845 = 0;
                        task->_28 = 1;
                    } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x100) {
                        lbl_2_bss_9E10 ^= 1;
                    } else if (lbl_803C77B8[lbl_2_bss_1A824C->_197863]._02 & 0x1000) {
                        fn_2_93C64();
                    }
                    if (lbl_2_bss_9E10 != 0) {
                        fn_2_489DC();
                    }
                }
                break;
            }
        }
        break;
    case 3:
        task->_0C->_10 = 1;
        fn_800B0A14_removeQueue();
        task->_28 = 0;
        break;
    }
}
