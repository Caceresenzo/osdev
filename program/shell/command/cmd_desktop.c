#include <kernel/tty.h>
#include <program/desktop.h>
#include <stdio.h>

void
	cmd_desktop_handler(char *name, char *args)
{
	(void) name;
	(void) args;
	printf("Starting desktop env...");
	for (int time = 0; time < 1000000; ++time) { printf(""); }
	terminal_clear();
	desktop_start();
}
