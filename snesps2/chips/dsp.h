#ifndef CHIP_DSP_H
#define CHIP_DSP_H

#include <tamtypes.h>

void dsp_init();
u8 dsp_read(u32 addr);
void dsp_write(u32 addr, u8 val);

#endif