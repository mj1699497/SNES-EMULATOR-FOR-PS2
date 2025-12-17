#ifndef OP_BRANCH_H
#define OP_BRANCH_H

void op_jmp_abs();
void op_jsr();
void op_rts();
void op_rtl();

void op_beq();
void op_bne();
void op_bcs();
void op_bcc();
void op_bmi();
void op_bpl();

#endif