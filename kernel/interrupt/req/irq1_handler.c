#include <driver/keyboard.h>
#include <kernel/interrupt.h>
#include <io.h>

void irq1_handler(void)
{
	keyboard_interrupt();
	outb(0x20, 0x20);
}
