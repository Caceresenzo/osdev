#include <arch/i386/vga.h>

int
	putchar(int chr)
{
	char c;

	c = (char) chr;
	vga_write(&c, sizeof(char));
	return (chr);
}
