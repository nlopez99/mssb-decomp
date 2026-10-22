#ifndef __STATIC_MOVIE_H_
#define __STATIC_MOVIE_H_

#include "mssbTypes.h"

struct MovieHeader;
struct MoviePlayer;

void fn_800AD070(void);
u32 fn_800AD490(struct MoviePlayer* player);
void fn_800AD500(void);
u32 fn_800AD6BC(struct MoviePlayer* player);
s32 fn_800AD780(struct MoviePlayer* player);
void fn_800AD830(struct MoviePlayer* player);
void fn_800AD914(struct MoviePlayer* player);
void fn_800AD95C(struct MoviePlayer* player, u8 arg);
void fn_800AD9F4(struct MoviePlayer* player);
s32 fn_800ADAFC(void);
s32 fn_800ADB04(struct MovieHeader* header, struct MoviePlayer* player, u8 arg2, u8 stream);
void fn_800ADBFC(void);
void fn_800ADC40(void);
void fn_800ADD70(void);
void YUV2RGB(void);
void YUV2RGB_(void);
void fn_800AE5B8(void);
void fn_800AE8B8(void);
void MovStreamThread(void);
s32 fn_800AED24(void);
void MovDecodeThread(void);
void fn_800AF1A8(void);
void fn_800AF5FC(void);
void fn_800AF9B4(void);
void fn_800AFBF0(void);
void fn_800AFC10(void);
void fn_800AFD4C(void);
u8 fn_800AFFB0(void);
void fn_800AFFC0(u32 n);
void fn_800B0008(void);
void fn_800B0134(void);
void fn_800B0230(void);
void fn_800B0390(void);
void fn_800B03F4(void);
void fn_800B0580(void);
void fn_800B05E4(void);

#endif // !__STATIC_MOVIE_H_
