#include <kernel/interrupt.h>
#include <sys/types.h>

/*
** .selector = KERNEL_CODE_SEGMENT_OFFSET
** .type_attr = INTERRUPT_GATE
*/

void
	idt_set(int id, int selector, int type_attr, void *ptr)
{
	t_ulong	address;

	address = (t_ulong) ptr;
	g_idt[id].offset_lowerbits = address & 0xffff;
	g_idt[id].selector = selector;
	g_idt[id].zero = 0;
	g_idt[id].type_attr = type_attr;
	g_idt[id].offset_higherbits = (address & 0xffff0000) >> 16;
}
