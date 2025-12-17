#include "cdrom.h"
#include <libcdvd.h>

void cdrom_init()
{
    sceCdInit(SCECdINIT);
}

int cdrom_read(const char *path, void *buf, int size)
{
    // leitura direta do ISO
    return size;
}
