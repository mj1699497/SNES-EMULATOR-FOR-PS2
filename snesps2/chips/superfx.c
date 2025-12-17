#include "superfx.h"

typedef struct {
    u16 r[16];
    u32 pc;
    u32 cycles;
} SuperFX;

static SuperFX gsu;

void superfx_init()
{
    gsu.pc = 0;
}

void superfx_step(int cycles)
{
    gsu.cycles += cycles;
    while (gsu.cycles >= 1)
    {
        // fetch opcode
        // executar instrução GSU
        gsu.cycles--;
    }
}
case GSU_ADD:
    emit_add(r0, r1);
    break;
void superfx_exec(u32 pc)
{
    GSUBlock *blk = gsu_block_get(pc);
    if (!blk)
        blk = gsu_block_compile(pc);

    blk->func();
}
#include "../../dynarec/mips_emit.h"

switch (opcode)
{
    case GSU_ADD:
        emit_add(r0, r1);
        break;
}