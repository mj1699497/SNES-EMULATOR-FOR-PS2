#include "alu.h"

static inline void set_nz(u16 v, int bits)
{
    if (bits == 8) {
        cpu.p = (cpu.p & ~FLAG_Z) | ((v & 0xFF) ? 0 : FLAG_Z);
        cpu.p = (cpu.p & ~FLAG_N) | ((v & 0x80) ? FLAG_N : 0);
    } else {
        cpu.p = (cpu.p & ~FLAG_Z) | (v ? 0 : FLAG_Z);
        cpu.p = (cpu.p & ~FLAG_N) | ((v & 0x8000) ? FLAG_N : 0);
    }
}

void alu_adc(u16 val)
{
    int bits = (cpu.p & FLAG_M) ? 8 : 16;
    u32 a = cpu.a & (bits == 8 ? 0xFF : 0xFFFF);
    u32 c = (cpu.p & FLAG_C) ? 1 : 0;
    u32 r;

    if (cpu.p & FLAG_D) {
        /* Decimal mode (BCD) – versão correta */
        if (bits == 8) {
            r = (a & 0x0F) + (val & 0x0F) + c;
            if (r > 9) r += 6;
            r += (a & 0xF0) + (val & 0xF0);
            cpu.p = (r > 0x99) ? (cpu.p | FLAG_C) : (cpu.p & ~FLAG_C);
        } else {
            /* BCD 16-bit (raro, mas existe) */
            r = a + val + c;
            cpu.p = (r > 0x9999) ? (cpu.p | FLAG_C) : (cpu.p & ~FLAG_C);
        }
    } else {
        r = a + val + c;
        cpu.p = (r > (bits == 8 ? 0xFF : 0xFFFF))
            ? (cpu.p | FLAG_C) : (cpu.p & ~FLAG_C);
        cpu.p = (~(a ^ val) & (a ^ r) & (bits == 8 ? 0x80 : 0x8000))
            ? (cpu.p | FLAG_V) : (cpu.p & ~FLAG_V);
    }

    cpu.a = (cpu.a & (bits == 8 ? 0xFF00 : 0)) | (r & (bits == 8 ? 0xFF : 0xFFFF));
    set_nz(cpu.a, bits);
}

void alu_sbc(u16 val)
{
    alu_adc(~val);
}

void alu_and(u16 val)
{
    cpu.a &= val;
    set_nz(cpu.a, (cpu.p & FLAG_M) ? 8 : 16);
}

void alu_ora(u16 val)
{
    cpu.a |= val;
    set_nz(cpu.a, (cpu.p & FLAG_M) ? 8 : 16);
}

void alu_eor(u16 val)
{
    cpu.a ^= val;
    set_nz(cpu.a, (cpu.p & FLAG_M) ? 8 : 16);
}

void alu_cmp(u16 reg, u16 val)
{
    u32 r = reg - val;
    cpu.p = (reg >= val) ? (cpu.p | FLAG_C) : (cpu.p & ~FLAG_C);
    set_nz(r, (cpu.p & FLAG_M) ? 8 : 16);
}
