#include <stdio.h>

void
	cmd_echo_handler(char *name, char *args)
{
	(void) name;
	printf("%s\n", args);
}
