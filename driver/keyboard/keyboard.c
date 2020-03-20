#include <driver/keyboard/keyboard.h>
#include <io.h>
#include <stdio.h>
#include <kernel/tty.h>
#include <sys/types.h>
#include <keys.h>

int shift = 0;

void
	keyboard_interrupt(void)
{
	t_uchar	scancode;

	scancode = inb();
	if (scancode & 0x80) {
		if (scancode == 0xAA)
			shift = 0;
	} else {
		if (scancode == 0x2a) {
			shift = 1;
		} else if (scancode == 0x1c) {
			printf("%c", '\n');
		} else if (scancode == 0x0e) {
			terminal_backspace();
		} else if (shift) {
			printf("%c", charset_get(scancode + 90));
		} else {
			printf("%c", charset_get(scancode));
		}
	}
}
