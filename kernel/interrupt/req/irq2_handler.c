#include <kernel/interrupt.h>

void irq2_handler(void)
{
	outb(0x20, 0x20);
}
