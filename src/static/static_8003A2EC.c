#include "static/static_8003A2EC.h"
#include "static/uitexture.h"
#include "Dolphin/gx.h"
#include "static/UnknownHomes_Static.h"
#include "Dolphin/mtx.h"
#include "string.h"

// A ring of decals (shadows) laid on the ground, drawn with one of 13 textures
typedef struct Decal {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec dir;
    /* 0x18 */ Vec side;
    /* 0x24 */ u8 alpha;
    /* 0x25 */ u8 tex;
    /* 0x26 */ u8 _26;
} Decal; // size: 0x28

typedef struct DecalSystem {
    /* 0x000 */ Decal decals[64];
    /* 0xA00 */ u16 head;
    /* 0xA02 */ u16 tail;
    /* 0xA04 */ u8 _A04[0xA84 - 0xA04];
    /* 0xA84 */ GXTexObj texObj[13];
    /* 0xC24 */ GXTlutObj tlut[13];
    /* 0xCC0 */ u8 texMode[13];
    /* 0xCD0 */ f32 halfSize[13][2];
    /* 0xD38 */ u8 enabled;
} DecalSystem;

typedef struct DecalColor {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
} DecalColor; // size: 0x3

typedef struct QueueTask {
    /* 0x00 */ u8 _00[0x10];
    /* 0x10 */ u16 _10;
} QueueTask;

typedef struct SaveBlock {
    /* 0x0 */ u16 sum;
    /* 0x2 */ u8 _2[2];
    /* 0x4 */ u8 data[0x4508];
} SaveBlock; // size: 0x450C

// The task fn_8003C00C runs
typedef struct MenuTask {
    /* 0x00 */ u8 _00[0x14];
    /* 0x14 */ u8 _14;
    /* 0x15 */ u8 _15;
    /* 0x16 */ u8 _16;
    /* 0x17 */ u8 _17;
    /* 0x18 */ u8 _18;
    /* 0x19 */ u8 _19;
    /* 0x1A */ u8 _1A;
    /* 0x1B */ u8 _1B;
    /* 0x1C */ u8 _1C;
    /* 0x1D */ u8 _1D;
    /* 0x1E */ u8 _1E;
    /* 0x1F */ u8 _1F;
    /* 0x20 */ u8 _20;
    /* 0x21 */ u8 _21;
} MenuTask;

typedef struct SaveHeader {
    /* 0x000 */ u8 _00[0x36];
    /* 0x036 */ u8 _36[0x10];
    /* 0x046 */ u8 _46[3];
    /* 0x049 */ u8 _49[3];
    /* 0x04C */ u8 _4C;
    /* 0x04D */ u8 _4D;
    /* 0x04E */ u8 _4E;
    /* 0x04F */ u8 _4F[0xF7];
    /* 0x146 */ u8 _146[2];
    /* 0x148 */ u8 _148[0x454];
    /* 0x59C */ u8 _59C;
    /* 0x59D */ u8 _59D[6];
    /* 0x5A3 */ u8 _5A3[6];
    /* 0x5A9 */ u8 _5A9[3];
    /* 0x5AC */ int _5AC;
} SaveHeader; // size: 0x5B0

// The save file, checksummed as a header and three blocks
typedef struct SaveFile {
    /* 0x000 */ u8 _00[0x44];
    /* 0x044 */ u16 headerSum;
    /* 0x046 */ u8 _46[2];
    /* 0x048 */ SaveHeader header;
    /* 0x5F8 */ SaveBlock blocks[3];
} SaveFile;

// The game's copy of the saved data
typedef struct SaveData {
    /* 0x0000 */ u8 blocks[3][0x4508];
    /* 0xCF18 */ u8 _CF18[0x36];
    /* 0xCF4E */ u8 _CF4E[0x10];
    /* 0xCF5E */ u8 _CF5E[3];
} SaveData;

typedef struct MenuSlot {
    /* 0x0 */ s32 _0;
    /* 0x4 */ s32 _4;
} MenuSlot; // size: 0x8

extern u8 GetDrawShadows(void);
extern void fn_800BD1E8(void (*callback)(MtxPtr, GXTevStageID*, GXTexCoordID*, GXTexMapID*, u8*, u8*));
extern void fn_800BEB3C(void);
extern u16 fn_800ABB14(void* data, s32 size);
extern s32 fn_800ACC6C(s32 arg0, s32 size, s32 align);
extern void* fn_800B0A5C_insertQueue(void (*callback)(void), s32 priority);

// A texture file entry: its header word, then the texture
typedef struct TextureEntry {
    /* 0x00 */ u32 _00;
    /* 0x04 */ TextureDesc desc;
} TextureEntry;

extern struct {
    /* 0x00 */ u8 _00[0x54];
    /* 0x54 */ u32 badBlocks;
} lbl_803C50E8;

extern GXTexObj lbl_803C50B0;
extern GXTlutObj lbl_803C50DC;
extern u16 lbl_800F7AC0[16];
extern TextureDesc lbl_800F7AE0;

extern QueueTask* lbl_803CC1B8;
extern s32 lbl_803CBC48;
extern s32 lbl_803CBC4C;
extern s32 lbl_803CBC50;

extern u8 lbl_8023DD80[];
extern ScreenEffect lbl_803C5090;

extern SaveFile lbl_802D4B00;
extern SaveData lbl_80354768;
extern u8 lbl_80361B20[0xF7];
extern u8 lbl_803616CC[0x454];
extern struct {
    /* 0x00 */ u8 _00[0x1F];
    /* 0x1F */ u8 _1F;
} lbl_80366158;
extern struct {
    /* 0x000 */ u8 _000[0x398];
    /* 0x398 */ u8 _398;
} lbl_800EF808;
typedef struct StarEntry {
    /* 0x0 */ s16 id;
    /* 0x2 */ u8 _2[4];
} StarEntry; // size: 0x6

extern union {
    u8 raw[0x4508];
    struct {
        /* 0x0000 */ u8 _0000[0x1606];
        /* 0x1606 */ s8 _1606;
        /* 0x1607 */ u8 _1607[0x40B8 - 0x1607];
        /* 0x40B8 */ StarEntry entries[9];
        /* 0x40EE */ u8 _40EE[0x43BC - 0x40EE];
        /* 0x43BC */ s16 _43BC;
        /* 0x43BE */ u8 _43BE[0x4415 - 0x43BE];
        /* 0x4415 */ u8 _4415;
        /* 0x4416 */ u8 _4416[0x441B - 0x4416];
        /* 0x441B */ u8 _441B;
        /* 0x441C */ u8 _441C;
    } s;
} starMissionCompletionTracker;
extern void fn_8002128C(u8 arg0);

MenuSlot lbl_802D4AE0[4];
DecalSystem lbl_802D3D80;

DecalColor lbl_803CB828 = { 0 };
f32 lbl_803CB82C = -0.001f;

s32 lbl_803CBCA8;
u8 lbl_803CBCAC;
s32 lbl_803CBCB0;
u8 lbl_803CBCB4;
s32 lbl_803CBCB8;
s32 lbl_803CBCBC;

// .text:0x8004153C size:0x40
void fn_8004153C(void) {
    lbl_803CBC50 = 0x2380;
    lbl_803CBC4C = 0xE60;
    lbl_803CBC48 = fn_800ACC6C(1, 0x2380, 0x10000);
}

// .text:0x80041348 size:0x1F4
s32 fn_80041348(void) {
    s32 ok = 1;
    s32 i;
    s32 j;

    if (starMissionCompletionTracker.s._1606 != 0 && starMissionCompletionTracker.s._441B == 0) {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (starMissionCompletionTracker.s.entries[i].id == starMissionCompletionTracker.s.entries[j].id && i != j) {
                    ok = 0;
                }
            }
        }
        if (starMissionCompletionTracker.s._4415 >= 4) {
            ok = 0;
        }
        if (starMissionCompletionTracker.s._43BC < 0 || starMissionCompletionTracker.s._43BC > 1000) {
            ok = 0;
        }
    } else {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (starMissionCompletionTracker.s.entries[i].id == starMissionCompletionTracker.s.entries[j].id && i != j) {
                    ok = 0;
                }
            }
        }
        if (starMissionCompletionTracker.s._4415 >= 4) {
            ok = 0;
        }
        if (starMissionCompletionTracker.s._43BC < 0 || starMissionCompletionTracker.s._43BC > 1000) {
            ok = 0;
        }
        if (starMissionCompletionTracker.s._441C >= 6) {
            ok = 0;
        }
    }
    return ok;
}

// .text:0x80041150 size:0x1F8
void fn_80041150(u8 mask, u8 slot) {
    SaveFile* save = &lbl_802D4B00;
    SaveBlock* block = save->blocks;
    u8* src46 = save->header._46;
    u8* src00 = save->header._00;
    u8* src36 = save->header._36;
    u8* dst;
    s32 i;

    if (mask & 5) {
        fn_8002128C(save->header._4C);
        lbl_800EF808._398 = save->header._4D;
        lbl_80366158._1F = save->header._4E;
        memcpy(lbl_80361B20, save->header._4F, sizeof(save->header._4F));
        memcpy(lbl_803616CC, save->header._148, sizeof(save->header._148));
        g_d_GameSettings._12 = save->header._59C;
        memcpy(&g_d_GameSettings._13_arr[1], save->header._59D, sizeof(save->header._59D));
        memcpy(g_d_GameSettings._1A, save->header._5A3, sizeof(save->header._5A3));
        g_d_GameSettings._00 = save->header._5AC;
        memcpy(lbl_80354768._CF18, src00, sizeof(lbl_80354768._CF18));
        memcpy(lbl_80354768._CF4E, src36, sizeof(lbl_80354768._CF4E));
    }
    if (mask & 2) {
        if (slot != 3) {
            dst = lbl_80354768.blocks[slot];
            memcpy(dst, block[slot].data, sizeof(block[slot].data));
            memcpy(starMissionCompletionTracker.raw, dst, sizeof(starMissionCompletionTracker.raw));
            return;
        }
        for (i = 0; i < 3; i++) {
            memcpy(lbl_80354768.blocks[i], block[i].data, sizeof(block[i].data));
        }
        memcpy(lbl_80354768._CF5E, src46, sizeof(lbl_80354768._CF5E));
        memcpy(lbl_80354768._CF18, src00, sizeof(lbl_80354768._CF18));
        memcpy(lbl_80354768._CF4E, src36, sizeof(lbl_80354768._CF4E));
    }
}

// .text:0x80041074 size:0xDC
// 99.64%: both checksum compares take their operands in the other order (cmplw r0,r3)
s32 fn_80041074(SaveFile* save, s32 arg1, s32 mask) {
    SaveHeader* header = &save->header;
    u32 bit;
    SaveBlock* block;
    s32 i;

    lbl_803C50E8.badBlocks = 0;
    for (i = 0; i < 4; i++) {
        bit = 1 << i;
        if (mask & bit) {
            if (i == 0) {
                if (save->headerSum != fn_800ABB14(header, sizeof(save->header))) {
                    lbl_803C50E8.badBlocks = bit;
                    break;
                }
            } else {
                block = &save->blocks[i - 1];
                if (block->sum != fn_800ABB14(block->data, sizeof(block->data))) {
                    lbl_803C50E8.badBlocks |= bit;
                }
            }
        }
    }
    if (lbl_803C50E8.badBlocks != 0) {
        return 0xB;
    }
    return 0x11;
}

// .text:0x80040FE0 size:0x94
s32 fn_80040FE0(SaveFile* save) {
    SaveHeader* header = &save->header;
    SaveBlock* block;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i == 0) {
            save->headerSum = fn_800ABB14(header, sizeof(save->header));
        } else {
            block = &save->blocks[i - 1];
            block->sum = fn_800ABB14(block->data, sizeof(block->data));
        }
    }
    return 0x11;
}

// .text:0x80040C14 size:0x3CC
void fn_80040C14(void) {}

// .text:0x8004053C size:0x6D8
void fn_8004053C(void) {}

// .text:0x8003F2B8 size:0x1284
void fn_8003F2B8(void) {}

// .text:0x8003F23C size:0x7C
void fn_8003F23C(void) {
    MenuTask* task = fn_800B0A5C_insertQueue(fn_8003F2B8, 0x8000);

    task->_14 = 0;
    task->_15 = 0;
    task->_16 = 0;
    task->_17 = 0;
    task->_18 = 0;
    task->_1A = 0;
    task->_1B = 7;
    task->_1D = 0;
    task->_21 = 0;
    lbl_803CC1B8->_10 = 0;
    lbl_802D4AE0[1]._4 = 0;
    lbl_802D4AE0[1]._0 = 0;
    lbl_802D4AE0[0]._4 = 0;
    lbl_802D4AE0[0]._0 = 0;
}

// .text:0x8003E8D8 size:0x964
void fn_8003E8D8(void) {}

// .text:0x8003C00C size:0x28CC
void fn_8003C00C(void) {}

// .text:0x8003BF54 size:0xB8
void fn_8003BF54(u8 arg0, u8 arg1, u8 slot, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    MenuTask* task = fn_800B0A5C_insertQueue(fn_8003C00C, 0x8000);
    MenuSlot* entry;

    task->_14 = 0;
    task->_15 = arg0;
    task->_16 = arg1;
    task->_17 = slot;
    task->_18 = arg3;
    task->_19 = arg4;
    task->_1A = arg5;
    entry = &lbl_802D4AE0[slot];
    task->_1B = arg6;
    task->_1D = 0;
    task->_20 = arg7;
    task->_21 = arg8;
    entry->_4 = 0;
    entry->_0 = 0;
    task->_1F = 2;
    lbl_803CC1B8->_10 = 0;
}

// .text:0x8003BB90 size:0x3C4
void fn_8003BB90(void) {}

// .text:0x8003B5B0 size:0x5E0
void fn_8003B5B0(void) {}

// .text:0x8003AECC size:0x6E4
void fn_8003AECC(void) {}

// .text:0x8003AE70 size:0x5C
u8 fn_8003AE70(s32 kind) {
    u8 value = 0;

    switch (kind) {
    case 0:
        value = lbl_802D4B00.header._4D;
        break;
    case 1:
        value = lbl_802D4B00.header._4C;
        break;
    case 2:
        value = lbl_802D4B00.header._4E;
        break;
    }
    return value;
}

// .text:0x8003AE64 size:0xC
void fn_8003AE64(void) {
    lbl_803CBCB8 = 0;
}

// .text:0x8003AE5C size:0x8
void fn_8003AE5C(u8 value) {
    lbl_803CBCB4 = value;
}

// .text:0x8003AE54 size:0x8
u8 fn_8003AE54(void) {
    return lbl_803CBCB4;
}

// .text:0x8003AD84 size:0xD0
void fn_8003AD84(TextureEntry* entry) {
    GXInitTexObjCI(&lbl_803C50B0, entry->desc.image, entry->desc.width, entry->desc.height, GX_TF_C4,
                   (GXTexWrapMode)entry->desc.wrapS, (GXTexWrapMode)entry->desc.wrapT, GX_FALSE, GX_TLUT0);
    GXInitTlutObj(&lbl_803C50DC, lbl_800F7AC0, GX_TL_IA8, 16);
    GXInitTexObjLOD(&lbl_803C50B0, (GXTexFilter)entry->desc.minFilter, (GXTexFilter)entry->desc.magFilter,
                    entry->desc.minLOD, entry->desc.maxLOD, entry->desc.lodBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
    lbl_803CBCAC = 1;
}

// .text:0x8003AC90 size:0xF4
void fn_8003AC90(void) {
    GXColor color;

    color.a = 0xFF;
    color.b = lbl_803CBCB4;
    color.g = lbl_803CBCB4;
    color.r = lbl_803CBCB4;
    GXSetChanMatColor(GX_COLOR0A0, color);
    GXSetNumChans(1);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_RASC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_RASA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
}

// .text:0x8003A8A0 size:0x3F0
void fn_8003A8A0(void) {}

// .text:0x8003A85C size:0x44
void fn_8003A85C(u8 enabled) {
    lbl_802D3D80.enabled = enabled;
    lbl_802D3D80.head = 0;
    lbl_802D3D80.tail = 0;
    memset(lbl_802D3D80.texMode, 0, sizeof(lbl_802D3D80.texMode));
}

// .text:0x8003A848 size:0x14
void fn_8003A848(u8 r, u8 g, u8 b) {
    lbl_803CB828.r = r;
    lbl_803CB828.g = g;
    lbl_803CB828.b = b;
}

// .text:0x8003A6B0 size:0x198
void fn_8003A6B0(s32 i, TextureDesc* tex, f32 width, f32 height) {
    if (tex->tlut != NULL) {
        lbl_802D3D80.texMode[i] = 2;
        GXInitTexObjCI(&lbl_802D3D80.texObj[i], tex->image, tex->width, tex->height, (GXCITexFmt)tex->format,
                       (GXTexWrapMode)tex->wrapS, (GXTexWrapMode)tex->wrapT, GX_FALSE, i);
        GXInitTlutObj(&lbl_802D3D80.tlut[i], tex->tlut, (GXTlutFmt)tex->tlutFormat, tex->tlutCount);
    } else {
        lbl_802D3D80.texMode[i] = 1;
        GXInitTexObj(&lbl_802D3D80.texObj[i], tex->image, tex->width, tex->height, (GXTexFmt)tex->format,
                     (GXTexWrapMode)tex->wrapS, (GXTexWrapMode)tex->wrapT, GX_FALSE);
    }
    GXInitTexObjLOD(&lbl_802D3D80.texObj[i], (GXTexFilter)tex->minFilter, (GXTexFilter)tex->magFilter, tex->minLOD,
                    tex->maxLOD, tex->lodBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
    fn_8003A688(i, width, height);
}

// .text:0x8003A688 size:0x28
void fn_8003A688(s32 i, f32 width, f32 height) {
    lbl_802D3D80.halfSize[i][0] = width / 2.0f;
    lbl_802D3D80.halfSize[i][1] = height / 2.0f;
}

// .text:0x8003A550 size:0x138
// 98.53%: registers only; tex and the decal's offset and pointer take r27, r28 and r25 for r25, r27, r28
void fn_8003A550(s32 tex, Vec* pos, Vec* dir, u8 arg3) {
    Vec* ndir;
    u16 head = lbl_802D3D80.head;
    Decal* decal;
    f32 x;

    if (lbl_802D3D80.enabled) {
        decal = &lbl_802D3D80.decals[head];
        decal->tex = tex;
        ndir = &decal->dir;
        decal->pos = *pos;
        PSVECNormalize(dir, ndir);
        PSVECScale(ndir, lbl_802D3D80.halfSize[tex][0], &decal->side);
        x = -lbl_802D3D80.decals[head].side.z;
        lbl_802D3D80.decals[head].side.z = lbl_802D3D80.decals[head].side.x;
        lbl_802D3D80.decals[head].side.x = x;
        PSVECScale(ndir, lbl_802D3D80.halfSize[tex][1], ndir);
        lbl_802D3D80.decals[head].dir.y = lbl_803CB82C;
        lbl_802D3D80.decals[head].alpha = 0xFF;
        lbl_802D3D80.decals[head]._26 = arg3;
        lbl_802D3D80.head = (head + 1) % 64;
        lbl_802D3D80.tail = (lbl_802D3D80.tail + (lbl_802D3D80.head == lbl_802D3D80.tail)) % 64;
    }
}

// .text:0x8003A548 size:0x8
void fn_8003A548(s32 value) {
    lbl_803CBCA8 = value;
}

// .text:0x8003A540 size:0x8
void fn_8003A540(s32 value) {
    lbl_803CBCB0 = value;
}

// .text:0x8003A538 size:0x8
s32 fn_8003A538(void) {
    return lbl_803CBCB0;
}

// .text:0x8003A4C8 size:0x70
void fn_8003A4C8(void) {
    if (GetDrawShadows()) {
        GXSetTexCopySrc(0, 0, 640, 448);
        GXSetTexCopyDst(640, 448, GX_TF_RGB565, GX_FALSE);
        GXCopyTex(GetUITexture(), GX_TRUE);
        GXPixModeSync();
        fn_800BEB3C();
        fn_800BD1E8(fn_8003A37C);
    }
}

// .text:0x8003A37C size:0x14C
void fn_8003A37C(MtxPtr mtx, GXTevStageID* stage, GXTexCoordID* coord, GXTexMapID* map, u8* count, u8* mtxIdx) {
    lbl_800F7AE0.image = GetUITexture();
    SetDisplayStateTexture(&lbl_800F7AE0, *map, 0);
    GXSetTevOrder(*stage, *coord, *map, GX_COLOR0A0);
    GXSetTevColorIn(*stage, GX_CC_ZERO, GX_CC_TEXC, GX_CC_TEXA, GX_CC_CPREV);
    GXSetTevColorOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaIn(*stage, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
    GXSetTevAlphaOp(*stage, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTexCoordGen2(*coord, GX_TG_MTX3X4, GX_TG_POS, GX_TEXMTX0 + *mtxIdx * 3, GX_FALSE, GX_PTIDENTITY);
    GXLoadTexMtxImm(mtx, GX_TEXMTX0 + *mtxIdx * 3, GX_MTX3x4);
    (*count)++;
    (*mtxIdx)++;
    (*stage)++;
    (*coord)++;
    (*map)++;
}

// .text:0x8003A2EC size:0x90
void fn_8003A2EC(void) {
    lbl_803C5090.flags = 1;
    lbl_803C5090.alpha = 0x60;
    lbl_803C5090.scale = 30.0f;
    lbl_803C5090.jitterX = 1.0f;
    lbl_803C5090.jitterY = 1.0f;
    lbl_803C5090.width = 320;
    lbl_803C5090.height = 224;
    memset(lbl_8023DD80, 0, 640 * 480 * 2);
    lbl_803C5090._14 = 448;
    lbl_803C5090._1A = 0xFF;
    lbl_803C5090._1B = 0xFF;
    lbl_803C5090._1C = 0xFF;
}
