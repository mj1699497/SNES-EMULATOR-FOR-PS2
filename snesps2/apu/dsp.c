#include "dsp.h"
#include "mixer.h"

typedef struct {
    u16 pitch;
    u16 addr;
    s16 sample;
    s16 env;
} Voice;

static Voice voices[8];

void dsp_reset()
{
    for (int i = 0; i < 8; i++)
        voices[i].env = 0;
}

void dsp_render()
{
    mix_samples(voices);
}