#include <kernel/interrupt.h>
#include <kernel/ports.h>
#include <kernel/timer.h>
#include <stdio.h>

int32	timer_ticks = 0;

void
	timer_initizalier(uint32 frequency)
{
	uint32	divider;

	divider = BASE_CLOCK_HZ / frequency;
	printf("[timer] Divider: %d.\n", divider);
	if ((divider >> 16) != 0)
	{
		printf("[timer] Warning: frequency too slow (min ~= 20).\n");
		return;
	}
	outb(PIT_COMMAND, 0x36);
	outb(PIT_DATA_CHN0, divider & 0xFF);
	outb(PIT_DATA_CHN0, (divider >> 8) & 0xFF);
	interrupt_handler_register(IRQ0, &timer_interrupt_callback);
}

void
	timer_interrupt_callback(registers_t *regs)
{
	(void) regs;
	timer_ticks++;
	printf("[timer] Ticked: %d\n", timer_ticks);
}
