#include <arch/i386/vga.h>
#include <driver/keyboard.h>
#include <driver/serial.h>
#include <kernel/descriptor_tables.h>
#include <kernel.h>
#include <program/shell.h>
#include <stdio.h>

void
	kinit(void)
{
	cli();
	vga_initialize();
	descriptor_tables_initialize();
	keyboard_initialize();
	serial_initialize(PORT_COM1);
	sti();
	serial_write_str(PORT_COM1, "Hello World\n");
}

void
	kmain(void)
{
	kinit();
	printf("------------------------------------------\nHello, kernel World!\n");
//	timer_initizalier(20);
	shell_start();
	while (1)
		;
	printf("END");
}
