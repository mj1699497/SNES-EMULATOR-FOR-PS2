#ifndef APU_H
#define APU_H

#include <tamtypes.h>

void apu_init();
void apu_reset();
void apu_step(int cycles);
void apu_sync();

u8 apu_read(u16 addr);
void apu_write(u16 addr, u8 val);

#endif