#ifndef ADDR_H
#define ADDR_H

#include <tamtypes.h>

u32 addr_imm();
u32 addr_abs();
u32 addr_absx();
u32 addr_absy();
u32 addr_dp();
u32 addr_dpx();
u32 addr_dpy();
u32 addr_ind();
u32 addr_long();
u32 addr_longx();
u32 addr_stack_rel();
u32 addr_stack_rel_ind();

#endif
