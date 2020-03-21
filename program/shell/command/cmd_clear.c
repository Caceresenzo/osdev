#include <kernel/tty.h>

void
	cmd_clear_handler(char *name, char *args)
{
	(void) name;
	(void) args;
	terminal_clear();
}
