#include "stack.h"
#include "../system/memory.h"

void push8(u8 v)
{
    mem_write8(cpu.sp | (cpu.emulation ? 0x100 : 0), v);
    cpu.sp--;
}

void push16(u16 v)
{
    push8(v >> 8);
    push8(v & 0xFF);
}

u8 pop8()
{
    cpu.sp++;
    return mem_read8(cpu.sp | (cpu.emulation ? 0x100 : 0));
}

u16 pop16()
{
    u16 l = pop8();
    return l | (pop8() << 8);
}