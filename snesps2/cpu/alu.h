#ifndef ALU_H
#define ALU_H

#include "cpu65816.h"
#include <tamtypes.h>

void alu_adc(u16 val);
void alu_sbc(u16 val);
void alu_and(u16 val);
void alu_ora(u16 val);
void alu_eor(u16 val);
void alu_cmp(u16 reg, u16 val);

#endif