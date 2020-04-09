#include <kernel/interrupt.h>

void irq3_handler(void)
{
	outb(0x20, 0x20);
}
