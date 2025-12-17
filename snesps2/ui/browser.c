#include "browser.h"
#include "../io/usb.h"
#include "../io/cdrom.h"
#include "../io/zip.h"
#include "../system/rom.h"

void browser_draw()
{
    // lista arquivos
}

void browser_select()
{
    char path[256];
    browser_get_selected(path);

    if (is_zip(path))
        zip_load_rom(path);
    else
        rom_load(path);
}
