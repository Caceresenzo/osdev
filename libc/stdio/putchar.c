#include <stdio.h>
#include <kernel/tty.h>

int
	putchar(int chr) {
	char c;

	c = (char) chr;
	terminal_write(&c, sizeof(c));
	return (chr);
}
