#include <arch/i386/vga.h>
#include <driver/keyboard.h>
#include <kernel/descriptor_tables.h>
#include <kernel/interrupt.h>
#include <program/shell.h>
#include <stdio.h>

void
	inter4(registers_t *regs)
{
	printf(".");
}

void kmain(void) {
	vga_initialize();
	descriptor_tables_initialize();
	keyboard_initialize();
	interrupt_handler_register(IRQ0, &inter4);
	asm volatile("int $32"); // Test
	printf("Hello, kernel World!\n");
	shell_start();
	while (1);
	printf("END");
}
