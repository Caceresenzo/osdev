#include <kernel/interrupt.h>

void irq7_handler(void)
{
	outb(0x20, 0x20);
}
