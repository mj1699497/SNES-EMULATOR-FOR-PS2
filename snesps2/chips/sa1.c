#include "sa1.h"
#include "../cpu/cpu65816.h"

static CPU65816 sa1cpu;

void sa1_init()
{
    // reset SA-1 CPU
}

void sa1_step(int cycles)
{
    for (int i = 0; i < cycles; i++)
        cpu_step(); // SA-1 usa core separado
    while (cycles--)
    {
        dynarec_exec_sa1(sa1.pc);
    }
}
void snes_frame()
{
    for (int i = 0; i < CPU_CYCLES; i++)
    {
        dynarec_exec(cpu.pc);
        sa1_step(1);
    }
}