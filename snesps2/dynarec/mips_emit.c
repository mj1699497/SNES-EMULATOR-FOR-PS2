#include "mips_emit.h"

static u32 *code;

void emit_prologue()
{
    *code++ = 0x27BDFFE0; // addiu sp,sp,-32
}

void emit_epilogue()
{
    *code++ = 0x27BD0020; // addiu sp,sp,32
    *code++ = 0x03E00008; // jr ra
    *code++ = 0x00000000;
}

void emit_adc_imm(u16 val)
{
    // exemplo simplificado
    *code++ = 0x24840000 | val; // addiu a0,a0,val
void emit_add(u32 dst, u32 src)
{
    EMIT(0x00000020 | (src << 21) | (dst << 16));
}