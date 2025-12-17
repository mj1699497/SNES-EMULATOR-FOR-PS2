#include "render.h"
#include <gsKit.h>

static u16 framebuffer[256 * 224];

void render_begin()
{
    // limpa buffer
}

void render_pixel(int x, u16 color)
{
    framebuffer[x] = color;
}

void render_end()
{
    // envia framebuffer para GS
}