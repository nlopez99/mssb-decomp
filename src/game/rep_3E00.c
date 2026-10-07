#include "game/rep_3E00.h"
#include "header_rep_data.h"
#include "game/UnknownHomes_Game.h"
#include "string.h"

typedef struct {
    /* 0x00 */ void* _00;
    /* 0x04 */ u8 _04[0x10 - 0x4];
    /* 0x10 */ f32 _10;
    /* 0x14 */ u8 _14[0x1A - 0x14];
    /* 0x1A */ s16 _1A;
    /* 0x1C */ u8 _1C[0x5C - 0x1C];
} UnkAnimState3E00; // size: 0x5C

typedef struct {
    /* 0x00 */ u8 _00[0x34];
    /* 0x34 */ u8 _34[0x90 - 0x34];
} UnkActor3E00; // size: 0x90

extern struct {
    /* 0x0000 */ u8 _0000[0x68];
    /* 0x0068 */ UnkActor3E00* _0068;
    /* 0x006C */ u8 _006C[0x2D94 - 0x6C];
    /* 0x2D94 */ void* _2D94;
    /* 0x2D98 */ u8 _2D98[0x2D9C - 0x2D98];
    /* 0x2D9C */ u32* _2D9C;
    /* 0x2DA0 */ void* _2DA0[1][3]; // layout, geometry and texture of each model
    /* 0x2DAC */ u8 _2DAC[0x3078 - 0x2DAC];
    /* 0x3078 */ u16 _3078;
} lbl_8036E548;

extern struct {
    /* 0x00 */ void* _00[1];
    /* 0x04 */ UnkAnimState3E00 _04[1];
} lbl_3_common_bss_32724;

// rep_3310.h declares it void(void) to match its stub
extern void fn_3_11D2C8(s32 model, s32 first, s32 count, s32, s32);

extern void LoadActorLayout(void* layout);
extern void convertGeometryAndSknHeader(void* geo, void*);
extern void haveActLayoutPointToGeoHeader(void* layout, void* geo);
extern void convertTextureHeader(void* tex);
extern void fn_800BD190(void* geo, void* tex);
extern UnkActor3E00* ActorObjectInitTable(u16 count);
extern void* _OSAllocFromHeap(u32 align, u32 size);
extern void fn_80025C58(void* anim, void*);
extern void fn_80025DDC(void* anim);
extern void fn_80025FFC(void* anim, UnkAnimState3E00* state);
extern void fn_80025EEC(UnkAnimState3E00* state, s32, s32);

// .text:0x00166448 size:0x19C mapped:0x807A54DC
void fn_3_166448(void) {
    u32* entry;
    u32* file;
    void* layout;
    void* geo;
    void* tex;
    s32 i;
    s32 j;
    s32 k;

    file = lbl_8036E548._2D9C;
    i = 0;
    for (j = 0; j < 1; j++) {
        for (k = 0; k < 3; k++) {
            lbl_8036E548._2DA0[j][k] = (u8*)file + file[i++];
        }
    }
    for (j = 0; j < 1; j++) {
        entry = &file[i];
        lbl_3_common_bss_32724._00[j] = (u8*)file + entry[0];
        lbl_3_common_bss_32724._04[j]._00 = (u8*)file + entry[1];
        i += 2;
    }

    for (i = 0; i < 1; i++) {
        layout = lbl_8036E548._2DA0[i][0];
        geo = lbl_8036E548._2DA0[i][1];
        tex = lbl_8036E548._2DA0[i][2];
        LoadActorLayout(layout);
        convertGeometryAndSknHeader(geo, NULL);
        haveActLayoutPointToGeoHeader(layout, geo);
        convertTextureHeader(tex);
        fn_800BD190(geo, tex);
    }

    for (i = 0; i < 1; i++) {
        fn_80025DDC(lbl_3_common_bss_32724._00[i]);
        fn_80025FFC(lbl_3_common_bss_32724._00[i], &lbl_3_common_bss_32724._04[i]);
        fn_80025EEC(&lbl_3_common_bss_32724._04[i], 0, 0);
        if (i == 0) {
            lbl_3_common_bss_32724._04[i]._1A = 1;
        }
    }

    lbl_8036E548._3078 = 1;
    lbl_8036E548._2D94 = _OSAllocFromHeap(0x20, lbl_8036E548._3078 * 0x28);
    memset(lbl_8036E548._2D94, 0, lbl_8036E548._3078 * 0x28);
    lbl_8036E548._0068 = ActorObjectInitTable(lbl_8036E548._3078);
    fn_3_11D2C8(0, 0, 1, 0, 0);
    lbl_3_common_bss_32724._04[0]._10 = 0.5f;
    fn_80025C58(lbl_3_common_bss_32724._00[0], lbl_8036E548._0068->_34);
}
