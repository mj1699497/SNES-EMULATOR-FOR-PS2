#ifndef COMPARE_H
#define COMPARE_H

#include "../cpu/cpu65816.h"

typedef struct {
    u32 pc;
    u8 pb, db;
    u16 a, x, y, sp;
    u8 p;
    u32 cycles;
} CPUState;

void snapshot_cpu(CPUState *s);
int compare_cpu(CPUState *a, CPUState *b);

#endif