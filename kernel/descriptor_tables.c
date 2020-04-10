#include <common.h>
#include <kernel/descriptor_tables.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel.h>

void
	descriptor_tables_initialize(void)
{
	cli();
	gdt_initialize();
	idt_initialize();
	outb(0x21, 0xfd); // Only keyboard
	outb(0xa1, 0xff);
	sti();
}
