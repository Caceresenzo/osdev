#include <kernel/interrupt.h>
#include <io.h>

void irq10_handler(void)
{
	outb(0xA0, 0x20);
	outb(0x20, 0x20);
}
