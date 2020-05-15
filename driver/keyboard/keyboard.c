#include <arch/i386/vga.h>
#include <driver/keyboard.h>
#include <keys.h>
#include <stdio.h>

static int shift = 0;

void
	keyboard_initialize(void)
{
	interrupt_handler_register(IRQ1, &keyboard_interrupt);
	charset_use(&g_charsets[0]);
}

void
	keyboard_interrupt(registers_t *regs)
{
	uint8	scancode;

	(void) regs;
	scancode = inb(0x60);
	if (scancode & 0x80) {
		key_state_set(scancode & 0x7F, false);
		if (scancode == 0xAA)
			shift = 0;
	} else {
		key_state_set(scancode, true);
		if (!keyboard_callback_fire(scancode)) {
			if (scancode == 0x2a) {
				shift = 1;
			} else if (scancode == 0x1c) {
				printk("%c", '\n');
			} else if (scancode == 0x0e) {
				vga_backspace();
			} else if (shift) {
				printk("%c", charset_get(scancode + 90));
			} else {
				printk("%c", charset_get(scancode));
			}
		}
	}
}
