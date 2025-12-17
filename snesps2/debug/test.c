#include "test.h"
#include "compare.h"
#include "logger.h"
#include "../cpu/cpu65816.h"
#include "../dynarec/dynarec.h"

void run_test(int steps)
{
    CPUState ref, jit;

    for (int i = 0; i < steps; i++)
    {
        snapshot_cpu(&ref);
        cpu_step(); // interpretador

        snapshot_cpu(&jit);
        dynarec_exec(cpu.pc);

        if (compare_cpu(&ref, &jit))
        {
            log_cpu("DESYNC");
            while (1); // trava para depuração
        }
    }
}