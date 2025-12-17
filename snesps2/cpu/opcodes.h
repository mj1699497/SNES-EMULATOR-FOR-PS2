#ifndef OPCODES_H
#define OPCODES_H

void (*opcode_table[256])();

void op_brk();
void op_nop();
void op_lda_imm();
void op_lda_abs();
void op_sta_abs();
/* ... TODAS as outras ... */

#endif