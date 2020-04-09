#include <arch/i386/vga.h>

void
	cmd_clear_handler(char *name, char *args)
{
	(void) name;
	(void) args;
	vga_clear();
}
