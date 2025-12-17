# =========================================================
# Projeto
# =========================================================
EE_BIN  = snesps2.elf
EE_SRC  = snesps2

# =========================================================
# Arquivos fonte (.c)
# =========================================================
EE_C_SRCS = \
	snesps2/main.c \
	snesps2/apu/apu.c \
	snesps2/apu/dsp.c \
	snesps2/apu/mixer.c \
	snesps2/apu/spc700.c \
	snesps2/chips/cx4.c \
	snesps2/chips/dsp.c \
	snesps2/chips/sa1.c \
	snesps2/chips/sdd1.c \
	snesps2/chips/superfx.c \
	snesps2/cpu/alu.c \
	snesps2/cpu/cpu65816.c \
	snesps2/cpu/interrupt.c \
	snesps2/cpu/op_arith.c \
	snesps2/cpu/op_branch.c \
	snesps2/cpu/opcodes.c \
	snesps2/cpu/stack.c \
	snesps2/debug/compare.c \
	snesps2/debug/logger.c \
	snesps2/debug/profiler.c \
	snesps2/debug/test.c \
	snesps2/dynarec/block.c \
	snesps2/dynarec/dynarec.c \
	snesps2/dynarec/mips_emit.c \
	snesps2/input/multitap.c \
	snesps2/input/pad.c \
	snesps2/io/cdrom.c \
	snesps2/io/usb.c \
	snesps2/io/zip.c \
	snesps2/ppu/bg.c \
	snesps2/ppu/hdma.c \
	snesps2/ppu/obg.c \
	snesps2/ppu/ppu.c \
	snesps2/ppu/render.c \
	snesps2/ppu/vu1_render.c \
	snesps2/save/savestate.c \
	snesps2/save/sram.c \
	snesps2/system/frameskip.c \
	snesps2/system/memory.c \
	snesps2/system/save.c \
	snesps2/system/snes.c \
	snesps2/system/timing.c \
	snesps2/ui/browser.c \
	snesps2/ui/menu.c

# =========================================================
# Objetos
# =========================================================
EE_OBJS = $(EE_C_SRCS:.c=.o)

# =========================================================
# Includes
# =========================================================
EE_INCS = \
	-Isnesps2 \
	-Isnesps2/apu \
	-Isnesps2/chips \
	-Isnesps2/cpu \
	-Isnesps2/debug \
	-Isnesps2/dynarec \
	-Isnesps2/input \
	-Isnesps2/io \
	-Isnesps2/ppu \
	-Isnesps2/save \
	-Isnesps2/system \
	-Isnesps2/ui

# =========================================================
# Flags de compilação (performance)
# =========================================================
EE_CFLAGS = \
	-O3 \
	-G0 \
	-Wall \
	-fno-strict-aliasing \
	-fno-builtin \
	-mtune=r5900 \
	$(EE_INCS)

# =========================================================
# Bibliotecas PS2
# =========================================================
EE_LIBS = \
	-lpad \
	-lcdvd \
	-lfileXio \
	-lz \
	-lgsKit \
	-ldma \
	-lkernel \
	-lc

# =========================================================
# Regras
# =========================================================
all: $(EE_BIN)

$(EE_BIN): $(EE_OBJS)
	$(EE_CC) $(EE_CFLAGS) -o $@ $(EE_OBJS) $(EE_LIBS)

%.o: %.c
	$(EE_CC) $(EE_CFLAGS) -c $< -o $@

clean:
	rm -f $(EE_OBJS) $(EE_BIN)

rebuild: clean all