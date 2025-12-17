#include "logger.h"
#include "../cpu/cpu65816.h"
#include <stdio.h>

void log_cpu(const char *tag)
{
    printf("[%s] PC=%02X:%04X A=%04X X=%04X Y=%04X SP=%04X P=%02X CYC=%d\n",
        tag,
        cpu.pb, cpu.pc,
        cpu.a, cpu.x, cpu.y,
        cpu.sp, cpu.p,
        cpu.cycles
    );
}