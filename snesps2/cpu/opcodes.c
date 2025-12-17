#include "opcodes.h"
#include "cpu65816.h"
#include "../system/memory.h"

void op_nop()
{
    cpu.cycles += 2;
}

void op_lda_imm()
{
    if (cpu.p & FLAG_M) {
        cpu.a = (cpu.a & 0xFF00) | fetch8();
        cpu.p = (cpu.a & 0xFF) ? (cpu.p & ~FLAG_Z) : (cpu.p | FLAG_Z);
    } else {
        cpu.a = fetch16();
        cpu.p = cpu.a ? (cpu.p & ~FLAG_Z) : (cpu.p | FLAG_Z);
    }
    cpu.cycles += 2;
}

void op_sta_abs()
{
    u16 addr = fetch16();
    mem_write8((cpu.db << 16) | addr, cpu.a & 0xFF);
    if (!(cpu.p & FLAG_M))
        mem_write8((cpu.db << 16) | (addr + 1), cpu.a >> 8);
    cpu.cycles += 4;
}