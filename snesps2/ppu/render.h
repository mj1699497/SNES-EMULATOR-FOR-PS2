#ifndef RENDER_H
#define RENDER_H

#include <tamtypes.h>

void render_begin();
void render_pixel(int x, u16 color);
void render_end();

#endif