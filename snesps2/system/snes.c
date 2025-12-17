#include "snes.h"
#include "../cpu/cpu65816.h"
#include "../ppu/ppu.h"
#include "../apu/apu.h"
#include "memory.h"

void snes_init()
{
    mem_init();
    cpu_reset();
    ppu_init();
    apu_init();
}

void snes_frame()
{
    for (int i = 0; i < 29780; i++)
        cpu_step();

    ppu_render();
    apu_sync();
}
#include "../dynarec/dynarec.h"
#include "../chips/sa1/sa1.h"

void snes_frame()
{
    for (int i = 0; i < CPU_CYCLES; i++)
    {
        dynarec_exec(cpu.pc);
        sa1_step(1);
void snes_frame()
{
    int cycles = CYCLES_PER_FRAME;

    while (cycles--)
    {
        dynarec_exec(cpu.pc);
        sa1_step(1);
        superfx_step(1);
        apu_step(1);
    }

    ppu_render();
}