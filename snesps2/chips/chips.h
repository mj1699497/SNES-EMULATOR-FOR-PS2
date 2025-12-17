#ifndef CHIPS_H
#define CHIPS_H

#include <tamtypes.h>

typedef enum {
    CHIP_NONE,
    CHIP_SUPERFX,
    CHIP_SA1,
    CHIP_DSP,
    CHIP_CX4,
    CHIP_SDD1,
    CHIP_SPC7110
} ChipType;

void chips_init(ChipType type);
u8   chips_read(u32 addr);
void chips_write(u32 addr, u8 val);
void chips_step(int cycles);

#endif
