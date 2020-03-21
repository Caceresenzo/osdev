#include <program/shell.h>
#include <stddef.h>
#include <stdio.h>

void
	cmd_help_handler(char *name, char *args)
 {
	size_t	index;

	(void) name;
	(void) args;
	printf("--- HELP ---\n\n");
	index = 0;
	while (index < (sizeof(g_commands) / sizeof(t_command)))
	{
		printf("%s\n", g_commands[index].usage);
		printf(" > %s\n\n", g_commands[index].description);
		index++;
	}
	printf("--- HELP END ---\n");
}
