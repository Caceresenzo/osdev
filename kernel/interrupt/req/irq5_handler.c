#include <kernel/interrupt.h>

void irq5_handler(void)
{
	outb(0x20, 0x20);
}
