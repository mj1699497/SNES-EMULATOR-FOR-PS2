#ifndef SUPERFX_H
#define SUPERFX_H

#include <tamtypes.h>

void superfx_init();
void superfx_step(int cycles);
u8   superfx_read(u32 addr);
void superfx_write(u32 addr, u8 val);

#endif