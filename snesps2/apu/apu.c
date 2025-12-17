#include "apu.h"
#include "spc700.h"
#include "dsp.h"

static int apu_cycles;

void apu_init()
{
    spc700_reset();
    dsp_reset();
    apu_cycles = 0;
}

void apu_step(int cycles)
{
    apu_cycles += cycles;
    while (apu_cycles >= 1)
    {
        spc700_step();
        apu_cycles--;
    }
}

void apu_sync()
{
    dsp_render();
    while (audio_buffer_level() < TARGET_LEVEL)
        spc700_step();
}
