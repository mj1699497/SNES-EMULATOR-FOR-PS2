#include "memory.h"

u8 ram[0x20000];

u8 mem_read8(u32 addr)
{
    return ram[addr & 0x1FFFF];
}

void mem_write8(u32 addr, u8 val)
{
    ram[addr & 0x1FFFF] = val;
}
if (addr >= 0x300000 && addr <= 0x3FFFFF)
    return chips_read(addr);