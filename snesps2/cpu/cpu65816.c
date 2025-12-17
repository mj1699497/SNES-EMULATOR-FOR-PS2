#include "cpu65816.h"
#include "opcodes.h"
#include "../system/memory.h"

CPU65816 cpu;

static inline u8 fetch8()
{
    return mem_read8((cpu.pb << 16) | cpu.pc++);
}

static inline u16 fetch16()
{
    u16 v = fetch8();
    v |= fetch8() << 8;
    return v;
}

void cpu_reset()
{
    cpu.emulation = 1;
    cpu.p = FLAG_I | FLAG_Z;
    cpu.sp = 0x1FF;
    cpu.pb = 0;
    cpu.pc = mem_read16(0xFFFC);
}

void cpu_step()
{
    u8 opcode = fetch8();
    opcode_table[opcode]();
}