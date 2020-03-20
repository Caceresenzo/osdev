#include <kernel/interrupt.h>
#include <io.h>
#include <driver/keyboard/keyboard.h>

void irq1_handler(void)
{
	keyboard_interrupt();
	outb(0x20, 0x20);
}
