#include "static/static_800B0A14.h"

typedef struct QueueTask {
    /* 0x00 */ void (*func)(void* arg);
    /* 0x04 */ struct QueueTask* prev;
    /* 0x08 */ struct QueueTask* next;
    /* 0x0C */ struct QueueTask* parent;
    /* 0x10 */ u16 _10;
    /* 0x12 */ u16 priority;
    /* 0x14 */ s32 _14;
    /* 0x18 */ s64 _18[5];
} QueueTask; // size: 0x40

extern QueueTask lbl_803C7A24[64];
extern void PrepFilesToBeLoaded(void* arg);

QueueTask lbl_80111300 = { PrepFilesToBeLoaded };

u16 lbl_803CC1B0;
u16 lbl_803CC1B2;
u16 lbl_803CC1B4;
QueueTask* lbl_803CC1B8;

// .text:0x800B0CB8 size:0x70
void RunDrawScripts_with_stack_variables(void) {
    s32 rootArgs[7];
    s32 frameArgs[5];
    QueueTask* task;

    lbl_803CC1B8 = &lbl_80111300;
    lbl_80111300.func(rootArgs);
    task = &lbl_803C7A24[lbl_803CC1B0 * 2];
    do {
        lbl_803CC1B8 = task;
        task->func(frameArgs);
        task = task->next;
    } while (task != NULL);
}

// .text:0x800B0CB4 size:0x4
void nop_function(void* arg) {
}

// .text:0x800B0C80 size:0x34
void fn_800B0C80(void (*func)(void*)) {
    s32 i;
    QueueTask* task;

    if (func == NULL) {
        func = nop_function;
    }
    task = lbl_803C7A24;
    i = 3;
    do {
        task->func = func;
        task += 2;
    } while (--i);
}

// .text:0x800B0BE8 size:0x98
void resetAllDrawingStructs(void) {
    s32 i;
    QueueTask* task;

    task = lbl_803C7A24;
    i = 3;
    do {
        task[0].prev = NULL;
        task[0].next = &task[1];
        task[0].parent = &lbl_80111300;
        task[0]._10 = 0;
        task[0].priority = 0;
        task[1].prev = &task[0];
        task[1].next = NULL;
        task[1].parent = &lbl_80111300;
        task[1]._10 = 0;
        task[1].priority = 0xFFFF;
        task += 2;
    } while (--i);
    task = &lbl_803C7A24[6];
    i = 64 - 6;
    do {
        task->func = NULL;
        task++;
    } while (--i);
    lbl_803CC1B2 = 0;
    lbl_803CC1B0 = 0;
    lbl_803CC1B4 = 5;
}

// .text:0x800B0B2C size:0xBC
void resetAllDrawingStructs_tonop(void) {
    s32 i;
    QueueTask* task;

    resetAllDrawingStructs();
    task = lbl_803C7A24;
    i = 6;
    do {
        task->func = nop_function;
        task++;
    } while (--i);
}

// .text:0x800B0A5C size:0xD0
QueueTask* fn_800B0A5C_insertQueue(void (*func)(void*), u16 priority) {
    QueueTask* next;
    QueueTask* prev;
    QueueTask* task;

    do {
        lbl_803CC1B4 = ++lbl_803CC1B4 & 63;
    } while (lbl_803C7A24[lbl_803CC1B4].func != NULL);
    next = &lbl_803C7A24[lbl_803CC1B0 * 2];
    do {
        next = next->next;
    } while (next->priority < priority);
    task = &lbl_803C7A24[lbl_803CC1B4];
    prev = next->prev;
    next->prev = task;
    prev->next = task;
    task->func = func;
    task->prev = prev;
    task->next = next;
    task->parent = lbl_803CC1B8;
    task->_10 = 0;
    task->priority = priority;
    task->_14 = 0;
    task->_18[0] = 0;
    task->_18[1] = 0;
    task->_18[2] = 0;
    task->_18[3] = 0;
    task->_18[4] = 0;
    lbl_803CC1B2++;
    return task;
}

// .text:0x800B0A14 size:0x48
void fn_800B0A14_removeQueue(void) {
    if (lbl_803CC1B2 != 0) {
        QueueTask* prev = lbl_803CC1B8->prev;

        prev->next = lbl_803CC1B8->next;
        lbl_803CC1B8->next->prev = lbl_803CC1B8->prev;
        lbl_803CC1B8->func = NULL;
        lbl_803CC1B2--;
    }
}
