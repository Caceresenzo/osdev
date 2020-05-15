#include <common.h>
#include <kernel/interrupt.h>
#include <stdio.h>

char	*interrupt_errors[256] = { //
	[0x00] = "Division by zero exception", //
	[0x01] = "Debug exception", //
	[0x02] = "Non maskable interrupt", //
	[0x03] = "Breakpoint exception", //
	[0x04] = "'Into detected overflow'", //
	[0x05] = "Out of bounds exception", //
	[0x06] = "Invalid opcode exception", //
	[0x07] = "No coprocessor exception", //
	[0x08] = "Double fault (code)", //
	[0x09] = "Coprocessor segment overrun", //
	[0x0A] = "Bad TSS (code)", //
	[0x0B] = "Segment not present (code)", //
	[0x0C] = "Stack fault (code)", //
	[0x0D] = "General protection fault (code)", //
	[0x0E] = "Page fault (code)", //
	[0x0F] = "Unknown interrupt exception", //
	[16] = "Coprocessor fault", //
	[17] = "Alignment check exception", //
	[18] = "Machine check exception", //
	[19 ... 31] = "Reserved", //
	[32] = "Timer",
	[33] = "Keyboard",
	[34 ... 255] = NULL
};

isr_t	interrupt_handlers[256] = { NULL };

isr_t
	interrupt_handler_register(uint8 id, isr_t isr)
{
	isr_t old;

	printk("[isr] Registered int. handler for ID %d (%s) at %p\n", id, interrupt_errors[id], isr);
	old = interrupt_handlers[id];
	interrupt_handlers[id] = isr;
	return (old);
}

char
	*interrupt_error_get(uint8 id)
{
	return (interrupt_errors[id]);
}
