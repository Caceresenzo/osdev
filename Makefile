OS_NAME					= the-os
OS_BIN					= $(OS_NAME).bin
OS_ISO					= $(OS_NAME).iso

INCLUDE					= include
LINKER_FILE				= kernel/arch/i386/linker.ld

SOURCES_S				=	kernel/arch/i386/crti.S \
							kernel/arch/i386/crtn.S
SOURCES_ASM				=	kernel/arch/i386/boot.s \
							kernel/asm/gdt_flush.s \
							kernel/asm/idt_flush.s \
							kernel/asm/interrupt.s
SOURCES_C				=	./driver/keyboard/keyboard.c \
							./driver/keyboard/keyboard_callback.c \
							./driver/screen/screen_apply.c \
							./driver/screen/screen_init.c \
							./driver/screen/screen_set_offset.c \
							./driver/serial/serial.c \
							./kernel/arch/i386/vga.c \
							./kernel/common.c \
							./kernel/descriptor_tables.c \
							./kernel/gdt.c \
							./kernel/idt.c \
							./kernel/multiboot.c \
							./kernel/memory.c \
							./kernel/interrupt.c \
							./kernel/interrupt_registry.c \
							./kernel/kmain.c \
							./kernel/timer.c \
							./kernel/panic.c \
							./libc/bits/bitset8.c \
							./libc/bits/bitset16.c \
							./libc/bits/bitset32.c \
							./libc/bits/bitset64.c \
							./libc/graphics2d/graphics2d_clear.c \
							./libc/graphics2d/graphics2d_draw_char.c \
							./libc/graphics2d/graphics2d_draw_line_horizontal.c \
							./libc/graphics2d/graphics2d_draw_line_vertical.c \
							./libc/graphics2d/graphics2d_draw_string.c \
							./libc/graphics2d/graphics2d_fill.c \
							./libc/graphics2d/graphics2d_set_at.c \
							./libc/graphics2d/graphics2d_set_buffers.c \
							./libc/graphics2d/graphics2d_set_dimension.c \
							./libc/graphics2d/graphics2d_set_pen_char.c \
							./libc/graphics2d/graphics2d_set_pen_color.c \
							./libc/keys/charset/charset.c \
							./libc/keys/charset/charset_get.c \
							./libc/keys/charset/charset_use.c \
							./libc/keys/key_state.c \
							./libc/keys/key_state_get.c \
							./libc/keys/key_state_set.c \
							./libc/stdio/printf.c \
							./libc/stdio/putchar.c \
							./libc/stdio/puts.c \
							./libc/stdlib/abort.c \
							./libc/string/memcmp.c \
							./libc/string/memcpy.c \
							./libc/string/memmove.c \
							./libc/string/memset.c \
							./libc/string/strlen.c \
							./program/desktop/desktop.c \
							./program/edit/edit.c \
							./program/jumper/jumper.c \
							./program/shell/command/cmd_about.c \
							./program/shell/command/cmd_clear.c \
							./program/shell/command/cmd_desktop.c \
							./program/shell/command/cmd_echo.c \
							./program/shell/command/cmd_help.c \
							./program/shell/command/cmd_sizeof.c \
							./program/shell/shell.c

OBJECTS_S				= $(SOURCES_S:.S=.o)
OBJECTS_ASM				= $(SOURCES_ASM:.s=.o)
OBJECTS_C				= $(SOURCES_C:.c=.o)

QEMU					= /mnt/c/Windows/System32/cmd.exe /c "C:\\Program Files\\qemu\\qemu-system-i386.exe"

ISO_BUILD_DIR			= build/iso

GRUB_DIR				= grub

COMPILER_C_ARGUMENTS	= -std=gnu99 -ffreestanding -nostdlib -nodefaultlibs -fno-builtin -fno-stack-protector -nostartfiles -Wall -Wextra  -m32 -O2
ASSEMBLER_ARGUMENTS		= -std=gnu99 -ffreestanding -nostdlib -nodefaultlibs -fno-builtin -fno-stack-protector -nostartfiles -lgcc

.S.o:
	@i386-elf-gcc -c $< -o ${<:.S=.o}
	@echo [i386-elf-gcc] Compiling: ${<:.S=.o}

.s.o:
	@nasm $< -o ${<:.s=.o} -f elf
	@echo [nasm] Compiling: ${<:.s=.o}

.c.o:
	@i386-elf-gcc -c $< -o ${<:.c=.o} $(COMPILER_C_ARGUMENTS) -I$(INCLUDE)
	@echo [i386-elf-gcc] Compiling: ${<:.c=.o}

all: kernel

kernel: $(OS_BIN)
	
$(OS_BIN): $(OBJECTS_ASM) $(OBJECTS_C) $(OBJECTS_S)
	@i386-elf-gcc -T $(LINKER_FILE) -o $(OS_BIN) $(ASSEMBLER_ARGUMENTS) $(OBJECTS_ASM) $(OBJECTS_C) $(OBJECTS_S) 
	@echo [i386-elf-gcc] Assembling...
	@printf "[grub-file] Confirming multiboot... "
	@if grub-file --is-x86-multiboot $(OS_BIN); then echo ok; else echo failed; exit 1; fi

iso: $(OS_ISO)

$(OS_ISO): kernel
	mkdir -p $(ISO_BUILD_DIR)/boot/grub
	cp $(OS_BIN) $(ISO_BUILD_DIR)/boot/$(OS_BIN)
	cp $(GRUB_DIR)/grub.cfg $(ISO_BUILD_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(OS_ISO) $(ISO_BUILD_DIR)

run-kernel: $(OS_BIN) #,cpu,exec,in_asm -no-shutdown 
	$(QEMU) -D logs.txt -d int -no-reboot -kernel $(OS_BIN) -serial stdio -m 512M #-monitor stdio

run-iso: $(OS_ISO)
	$(QEMU) -cdrom $(OS_ISO)

re: clean all

clean:
	rm -rf $(ISO_BUILD_DIR)
	rm -f $(OBJECTS_ASM) $(OBJECTS_C) $(OBJECTS_S)
	rm -f $(OS_ISO) $(OS_BIN)

setup:
	sudo apt-get install mtools