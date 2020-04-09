#include <kernel/descriptor_tables.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>

void
	descriptor_tables_initialize(void)
{
	gdt_initialize();
	idt_initialize();
}
