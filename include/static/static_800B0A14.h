#ifndef __STATIC_STATIC_800B0A14_H_
#define __STATIC_STATIC_800B0A14_H_

#include "mssbTypes.h"

struct QueueTask;

void fn_800B0A14_removeQueue(void);
struct QueueTask* fn_800B0A5C_insertQueue(void (*func)(void*), u16 priority);
void resetAllDrawingStructs_tonop(void);
void resetAllDrawingStructs(void);
void fn_800B0C80(void (*func)(void*));
void nop_function(void* arg);
void RunDrawScripts_with_stack_variables(void);

#endif // !__STATIC_STATIC_800B0A14_H_
