#include "dynarec.h"
#include "block.h"
#include "../cpu/cpu65816.h"

void dynarec_init()
{
    // inicializa cache, memória executável
}

void dynarec_exec(u32 pc)
{
    Dynablock *b = block_get(pc);
    if (!b)
        b = block_compile(pc);

    if (b && b->func)
        b->func();
    else
        cpu_step(); // fallback
    Dynablock *blk = block_get(pc);

    if (!blk)
        blk = block_compile(pc);

    blk->func();
}