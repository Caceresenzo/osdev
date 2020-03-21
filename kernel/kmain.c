#include <kernel.h>
#include <kernel/interrupt.h>
#include <stdio.h>
#include <kernel/tty.h>
#include <keys.h>
#include <program/shell.h>

void kmain(void) {
	idt_init();
	charset_use(&g_charsets[0]);
	terminal_initialize();
	printf("Hello, kernel World!\n");
	shell_start();
	while (1);
	printf("END");
}
