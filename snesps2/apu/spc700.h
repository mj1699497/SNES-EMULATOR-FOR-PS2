#ifndef SPC700_H
#define SPC700_H

#include <tamtypes.h>

void spc700_reset();
void spc700_step();

extern u8 spc_ram[64 * 1024];

#endif