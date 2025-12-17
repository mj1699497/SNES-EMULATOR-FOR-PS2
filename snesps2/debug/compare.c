#include "compare.h"

void snapshot_cpu(CPUState *s)
{
    s->pc = cpu.pc;
    s->pb = cpu.pb;
    s->db = cpu.db;
    s->a  = cpu.a;
    s->x  = cpu.x;
    s->y  = cpu.y;
    s->sp = cpu.sp;
    s->p  = cpu.p;
    s->cycles = cpu.cycles;
}

int compare_cpu(CPUState *a, CPUState *b)
{
    return memcmp(a, b, sizeof(CPUState));
}
