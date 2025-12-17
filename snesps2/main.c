#include <tamtypes.h>
#include <kernel.h>
#include "ui/menu.h"
#include "system/snes.h"
#include "input/pad.h"

int main(int argc, char *argv[])
{
    init_pad();
    snes_init();

    while (1)
    {
        if (menu_active())
            menu_loop();
        else
            snes_frame();
    }
    return 0;
}
while (1)
{
    pad_poll();

    if (pad_combo(PAD_L3, PAD_R3))
        menu_open();

    if (menu_active())
        menu_loop();
    else {
        snes_frame();
        if (pad_pressed(PAD_L2)) save_state();
        if (pad_pressed(PAD_R2)) load_state();
    }
}
