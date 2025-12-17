#include "spc700.h"

typedef struct {
    u16 pc;
    u8 a, x, y, sp, psw;
} SPC700;

static SPC700 spc;
u8 spc_ram[64 * 1024];

void spc700_reset()
{
    spc.pc = spc_ram[0xFFFE] | (spc_ram[0xFFFF] << 8);
    spc.sp = 0xFF;
    spc.psw = 0x02;
}

void spc700_step()
{
    u8 op = spc_ram[spc.pc++];

    switch (op)
    {
        case 0x00: /* NOP */ break;
        case 0xCD: /* MOV X,#imm */ spc.x = spc_ram[spc.pc++]; break;
        /* tabela completa 256 instruções */
    }
}
#define AUDIO_BUFFER 2048