#ifndef DSP_H
#define DSP_H

#include <tamtypes.h>

void dsp_reset();
void dsp_write(u8 reg, u8 val);
void dsp_render();

#endif