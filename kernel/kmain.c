#include <arch/i386/vga.h>
#include <driver/keyboard.h>
#include <kernel/descriptor_tables.h>
#include <kernel/interrupt.h>
#include <program/shell.h>
#include <stdio.h>

void kmain(void) {
	vga_initialize();
	descriptor_tables_initialize();
	keyboard_initialize();
	printf("Hello, kernel World!\n");
	shell_start();
	while (1);
	printf("END");
}
