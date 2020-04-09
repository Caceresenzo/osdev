#include <arch/i386/vga.h>
#include <kernel/interrupt.h>
#include <keys.h>
#include <program/shell.h>
#include <stdio.h>

void kmain(void) {
	idt_initialize();
	charset_use(&g_charsets[0]);
	vga_initialize();
	printf("Hello, kernel World!\n");
	shell_start();
	while (1);
	printf("END");
}
