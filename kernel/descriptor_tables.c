#include <common.h>
#include <kernel/descriptor_tables.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel.h>

void
	descriptor_tables_initialize(void)
{
	gdt_initialize();
	idt_initialize();
}
