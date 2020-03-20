#include <kernel/interrupt.h>
#include <io.h>

void irq5_handler(void)
{
	outb(0x20, 0x20);
}
