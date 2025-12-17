#include "interrupt.h"
#include "stack.h"
#include "cpu65816.h"
#include "../system/memory.h"

void cpu_brk()
{
    push8(cpu.pb);
    push16(cpu.pc + 1);
    push8(cpu.p | 0x10);
    cpu.p |= FLAG_I;
    cpu.pc = mem_read16(cpu.emulation ? 0xFFFE : 0xFFE6);
    cpu.cycles += 7;
}

void cpu_irq()
{
    if (cpu.p & FLAG_I) return;
    push8(cpu.pb);
    push16(cpu.pc);
    push8(cpu.p);
    cpu.p |= FLAG_I;
    cpu.pc = mem_read16(cpu.emulation ? 0xFFFE : 0xFFEE);
    cpu.cycles += 7;
}

void cpu_nmi()
{
    push8(cpu.pb);
    push16(cpu.pc);
    push8(cpu.p);
    cpu.p |= FLAG_I;
    cpu.pc = mem_read16(cpu.emulation ? 0xFFFA : 0xFFEA);
    cpu.cycles += 7;
}

void cpu_rti()
{
    cpu.p = pop8();
    cpu.pc = pop16();
    cpu.pb = pop8();
    cpu.cycles += 6;
}