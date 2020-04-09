#include <common.h>
#include <kernel/interrupt.h>
#include <kernel/ports.h>
#include <stdio.h>

static bool
	handle(registers_t regs)
{
	uint8	index;
	isr_t	handler;

	index = regs.int_no & 0xFF;
	if ((handler = interrupt_handlers[index]) != NULL)
	{
		handler(&regs);
		return (true);
	}
	return (false);
}

void
	isr_handler(registers_t regs)
{
	printf("x");
	if (!handle(regs))
	{
		printf("[isr] Unhandled interrupt: %d (%s)\n", regs.int_no & 0xFF, interrupt_error_get(regs.int_no & 0xFF));
		while (true) ;
	}
}

void
	irq_handler(registers_t regs)
{
	printf("y");
	if (regs.int_no >= 40)
		outb(PIC_SLAVE_COMMAND, PIC_EOI);
	outb(PIC_MASTER_COMMAND, PIC_EOI);
	handle(regs);
}
