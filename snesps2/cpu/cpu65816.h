#ifndef CPU65816_H
#define CPU65816_H

#include <tamtypes.h>

typedef struct {
    u16 pc;
    u8  pb;
    u16 sp;
    u8  db;
    u16 a, x, y;
    u8  p;
    u8  emulation;
    u32 cycles;
} CPU65816;

extern CPU65816 cpu;

void cpu_reset();
void cpu_step();
void cpu_irq();
void cpu_nmi();

#endif