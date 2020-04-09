#include <kernel/interrupt.h>

void irq4_handler(void)
{
	outb(0x20, 0x20);
}
