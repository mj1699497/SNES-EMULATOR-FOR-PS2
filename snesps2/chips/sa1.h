#ifndef SA1_H
#define SA1_H

#include <tamtypes.h>

void sa1_init();
void sa1_step(int cycles);
u8   sa1_read(u32 addr);
void sa1_write(u32 addr, u8 val);

#endif