#include <arch/i386/vga.h>
#include <driver/keyboard.h>
#include <driver/serial.h>
#include <kernel/descriptor_tables.h>
#include <kernel/multiboot.h>
#include <kernel.h>
#include <program/shell.h>
#include <stdio.h>

static void
	kinit(multiboot_info *ptr)
{
	multiboot_info_store(ptr);

	cli();
	serial_initialize(PORT_COM1);
	serial_write_str(PORT_COM1, "Hello World\n");

	vga_initialize();
	descriptor_tables_initialize();
	keyboard_initialize();
	sti();
}

void
	kmain(multiboot_info *ptr)
{
	kinit(ptr);

	printk("--------------------------------------\nHello, kernel World!\n");
	multiboot_dump();

//	timer_initizalier(20);

	shell_start();
	while (1)
		;
	printk("END");
}
