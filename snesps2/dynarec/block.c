#include "block.h"
#include <string.h>

#define MAX_BLOCKS 4096

static Dynablock blocks[MAX_BLOCKS];

Dynablock* block_get(u32 pc)
{
    for (int i = 0; i < MAX_BLOCKS; i++)
        if (blocks[i].pc == pc)
            return &blocks[i];
    return NULL;
}

Dynablock* block_compile(u32 pc)
{
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        if (!blocks[i].pc)
        {
            blocks[i].pc = pc;
            // gerar código MIPS aqui
            return &blocks[i];
        }
    }
    return NULL;
}
static Dynablock *block_cache[0x100000]; // PC + banco

Dynablock *block_get(u32 pc)
{
    return block_cache[pc & 0xFFFFF];
}
