OS_NAME			= the-os
OS_BIN			= $(OS_NAME).bin
OS_ISO			= $(OS_NAME).iso

INCLUDE			= include
LINKER_FILE		= kernel/arch/i386/linker.ld

SOURCES_ASM		=	kernel/arch/i386/boot.S \
					kernel/arch/i386/crti.S \
					kernel/arch/i386/crtn.S
SOURCES_C		=	kernel/arch/i386/tty.c \
					kernel/kernel.c \
					libc/stdio/printf.c \
					libc/stdio/putchar.c \
					libc/stdio/puts.c \
					libc/stdlib/abort.c \
					libc/string/memcmp.c \
					libc/string/memcpy.c \
					libc/string/memmove.c \
					libc/string/memset.c \
					libc/string/strlen.c

OBJECTS_ASM		= $(SOURCES_ASM:.S=.o)
OBJECTS_C		= $(SOURCES_C:.c=.o)

QEMU			= /mnt/c/Windows/System32/cmd.exe /c "C:\\Program Files\\qemu\\qemu-system-i386.exe"

ISO_BUILD_DIR	= build/iso

GRUB_DIR		= grub

.S.o:
	i386-elf-gcc -c $< -o ${<:.S=.o}

.c.o:
	i386-elf-gcc -c $< -o ${<:.c=.o} -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I$(INCLUDE)

all: kernel

kernel: $(OS_BIN)
	
$(OS_BIN): $(OBJECTS_ASM) $(OBJECTS_C)
	i386-elf-gcc -T $(LINKER_FILE) -o $(OS_BIN) -ffreestanding -O2 -nostdlib $(OBJECTS_ASM) $(OBJECTS_C) -lgcc
	@printf "confirming multiboot... "
	@if grub-file --is-x86-multiboot $(OS_BIN); then echo ok; else echo failed; exit 1; fi

iso: $(OS_ISO)
	mkdir -p $(ISO_BUILD_DIR)/boot/grub
	cp $(OS_BIN) $(ISO_BUILD_DIR)/boot/$(OS_BIN)
	cp $(GRUB_DIR)/grub.cfg $(ISO_BUILD_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(OS_ISO) $(ISO_BUILD_DIR)

$(OS_ISO): kernel
	mkdir -p $(ISO_BUILD_DIR)/boot/grub
	cp $(OS_BIN) $(ISO_BUILD_DIR)/boot/$(OS_BIN)
	cp $(GRUB_DIR)/grub.cfg $(ISO_BUILD_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(OS_ISO) $(ISO_BUILD_DIR)

run-kernel: $(OS_BIN)
	$(QEMU) -kernel $(OS_BIN)

run-iso: $(OS_ISO)
	$(QEMU) -cdrom $(OS_ISO)

clean:
	rm -rf $(ISO_BUILD_DIR)
	rm -f $(OBJECTS_ASM) $(OBJECTS_C)
	rm -f $(OS_ISO) $(OS_BIN)