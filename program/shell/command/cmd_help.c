#include <common.h>
#include <program/shell.h>
#include <stdio.h>

void
	cmd_help_handler(char *name, char *args)
 {
	size_t	index;

	(void) name;
	(void) args;
	printk("--- HELP ---\n\n");
	index = 0;
	while (index < (sizeof(g_commands) / sizeof(t_command)))
	{
		printk("%s\n", g_commands[index].usage);
		printk(" > %s\n\n", g_commands[index].description);
		index++;
	}
	printk("--- HELP END ---\n");
}
