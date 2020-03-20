#include <kernel.h>
#include <kernel/interrupt.h>
#include <stdio.h>
#include <kernel/tty.h>
#include <keys.h>

void kmain(void) {
	idt_init();
	charset_use(&g_charsets[0]);
	terminal_initialize();
	printf("Hello, kernel World!\n");
	printf("Welcome to the new OS era!");

	while (1);
	printf("END");
}
