#ifndef PPU_H
#define PPU_H

#include <tamtypes.h>

void ppu_init();
void ppu_reset();
void ppu_step(int cycles);
void ppu_render_frame();

u8 ppu_read(u16 addr);
void ppu_write(u16 addr, u8 val);
VU1_DrawScanline(bg_buffer, obj_buffer);
#endif