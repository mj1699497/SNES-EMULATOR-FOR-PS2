#ifndef BLOCK_H
#define BLOCK_H

#define MAX_BLOCK_INSNS 128   // tamanho máximo do bloco JIT

typedef struct {
    u32 pc;
    void (*func)();
} Dynablock;

Dynablock *block_compile(u32 pc);
Dynablock *block_get(u32 pc);

#endif