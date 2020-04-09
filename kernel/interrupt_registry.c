#include <common.h>
#include <kernel/interrupt.h>

char	*interrupt_errors[256] = { //
	[0] = "Division by zero exception", //
	[1] = "Debug exception", //
	[2] = "Non maskable interrupt", //
	[3] = "Breakpoint exception", //
	[4] = "'Into detected overflow'", //
	[5] = "Out of bounds exception", //
	[6] = "Invalid opcode exception", //
	[7] = "No coprocessor exception", //
	[8] = "Double fault (code)", //
	[9] = "Coprocessor segment overrun", //
	[10] = "Bad TSS (code)", //
	[11] = "Segment not present (code)", //
	[12] = "Stack fault (code)", //
	[13] = "General protection fault (code)", //
	[14] = "Page fault (code)", //
	[15] = "Unknown interrupt exception", //
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

	printf("[isr] Registered interrupt handler for ID %d (%s) at address %x\n", id, interrupt_errors[id], isr);
	old = interrupt_handlers[id];
	interrupt_handlers[id] = isr;
	return (old);
}

char
	*interrupt_error_get(uint8 id)
{
	return (interrupt_errors[id]);
}
