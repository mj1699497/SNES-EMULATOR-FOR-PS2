#include "op_arith.h"
#include "alu.h"
#include "../system/memory.h"

void op_adc_imm()
{
    u16 v = (cpu.p & FLAG_M) ? fetch8() : fetch16();
    alu_adc(v);
    cpu.cycles += 2;
}

void op_sbc_abs()
{
    u16 addr = fetch16();
    u16 v = mem_read8((cpu.db << 16) | addr);
    if (!(cpu.p & FLAG_M))
        v |= mem_read8((cpu.db << 16) | (addr + 1)) << 8;
    alu_sbc(v);
    cpu.cycles += 4;
}