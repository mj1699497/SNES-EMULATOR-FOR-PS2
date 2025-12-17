#ifndef MIPS_EMIT_H
#define MIPS_EMIT_H

#include <tamtypes.h>

void emit_prologue();
void emit_epilogue();
void emit_load_a();
void emit_adc_imm(u16 val);

#endif