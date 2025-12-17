#include "menu.h"
#include "browser.h"
#include "../input/pad.h"

static int active = 1;

void menu_init() { active = 1; }

int menu_active() { return active; }

void menu_open() { active = 1; }

void menu_close() { active = 0; }

void menu_loop()
{
    browser_draw();

    if (pad_pressed(PAD_CROSS))
        browser_select();

    if (pad_pressed(PAD_START))
        menu_close();
}