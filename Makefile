OS_NAME			= os
OS_BIN			= $(OS_NAME).bin
OS_ISO			= $(OS_NAME).iso

SOURCES_ASM		= boot.s
SOURCES_C		= kernel.c

OBJECTS_ASM		= $(SOURCES_ASM:.s=.o)
OBJECTS_C		= $(SOURCES_C:.c=.o)

.s.o:
	i386-elf-as $< -o ${<:.s=.o}

.c.o:
	i386-elf-gcc -c $< -o${<:.c=.o} -std=gnu99 -ffreestanding -O2 -Wall -Wextra

all: kernel

kernel: $(OBJECTS_ASM) $(OBJECTS_C)
	i386-elf-gcc -T linker.ld -o $(OS_BIN) -ffreestanding -O2 -nostdlib $(OBJECTS_ASM) $(OBJECTS_C) -lgcc
	@printf "confirming multiboot... "
	@if grub-file --is-x86-multiboot $(OS_BIN); then echo ok; else echo failed; exit 1; fi

iso: kernel
	rm -rf isodir/boot/grub
	mkdir -p isodir/boot/grub
	cp $(OS_BIN) isodir/boot/$(OS_BIN)
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(OS_ISO) isodir

run-kernel: kernel
	/mnt/c/Windows/System32/cmd.exe /c "C:\\Program Files\\qemu\\qemu-system-i386.exe" -kernel $(OS_BIN)

run-iso: iso
	/mnt/c/Windows/System32/cmd.exe /c "C:\\Program Files\\qemu\\qemu-system-i386.exe" -cdrom $(OS_ISO)

clean:
	rm -rf isodir
	rm -f $(OBJECTS_ASM) $(OBJECTS_C)
	rm -f $(OS_ISO) $(OS_BIN)