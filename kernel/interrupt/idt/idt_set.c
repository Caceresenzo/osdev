#include <kernel/interrupt.h>

/*
** Set an entry in the Interupt Descriptor Table
**
** @param selector
** 				KERNEL_CODE_SEGMENT_OFFSET
** @param type_attr
** 				INTERRUPT_GATE
*/

void
	idt_set(int id, int selector, int type_attr, void *ptr)
{
	uint64	address;

	address = (uint64) ptr;
	g_idt[id].offset_lowerbits = address & 0xffff;
	g_idt[id].selector = selector;
	g_idt[id].zero = 0;
	g_idt[id].type_attr = type_attr;
	g_idt[id].offset_higherbits = (address & 0xffff0000) >> 16;
}
