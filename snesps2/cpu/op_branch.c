#include "op_branch.h"
#include "stack.h"
#include "cpu65816.h"

static inline s8 fetch_rel()
{
    return (s8)fetch8();
}

void op_jmp_abs()
{
    cpu.pc = fetch16();
    cpu.cycles += 3;
}

void op_jsr()
{
    u16 addr = fetch16();
    push16(cpu.pc - 1);
    cpu.pc = addr;
    cpu.cycles += 6;
}

void op_rts()
{
    cpu.pc = pop16() + 1;
    cpu.cycles += 6;
}

void op_rtl()
{
    cpu.pc = pop16();
    cpu.pb = pop8();
    cpu.cycles += 6;
}

#define BRANCH(cond) \
    do { s8 off = fetch_rel(); if (cond) cpu.pc += off; cpu.cycles += 2; } while (0)

void op_beq() { BRANCH(cpu.p & FLAG_Z); }
void op_bne() { BRANCH(!(cpu.p & FLAG_Z)); }
void op_bcs() { BRANCH(cpu.p & FLAG_C); }
void op_bcc() { BRANCH(!(cpu.p & FLAG_C)); }
void op_bmi() { BRANCH(cpu.p & FLAG_N); }
void op_bpl() { BRANCH(!(cpu.p & FLAG_N)); }