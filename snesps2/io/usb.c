#include "usb.h"
#include <fileXio_rpc.h>

void usb_init()
{
    fileXioInit();
}

int usb_read(const char *path, void *buf, int size)
{
    int fd = fileXioOpen(path, O_RDONLY, 0);
    int r = fileXioRead(fd, buf, size);
    fileXioClose(fd);
    return r;
}