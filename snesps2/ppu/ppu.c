#include "ppu.h"
#include "render.h"
#include "hdma.h"
#include "../cpu/cpu65816.h"

typedef struct {
    u16 vram_addr;
    u8  bgmode;
    u8  brightness;
    int scanline;
    int dot;
    int vblank;
} PPUState;

static PPUState ppu;

void ppu_init()
{
    ppu_reset();
}

void ppu_reset()
{
    ppu.scanline = 0;
    ppu.dot = 0;
    ppu.vblank = 0;
}

void ppu_step(int cycles)
{
    ppu.dot += cycles * 2; // PPU roda 2x CPU

    while (ppu.dot >= 341)
    {
        ppu.dot -= 341;
        ppu.scanline++;

        hdma_run_scanline(ppu.scanline);

        if (ppu.scanline == 224)
            ppu.vblank = 1;

        if (ppu.scanline >= 262)
        {
            ppu.scanline = 0;
            ppu.vblank = 0;
            ppu_render_frame();
        }
    }
}
void ppu_render()
{
    for (int y = 0; y < 224; y++)
        vu1_draw_scanline(y);
}