#ifndef STACK_H
#define STACK_H

#include "cpu65816.h"
#include <tamtypes.h>

void push8(u8 v);
void push16(u16 v);
u8 pop8();
u16 pop16();

#endif