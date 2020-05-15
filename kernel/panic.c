#include <common.h>
#include <stdio.h>
#include <stdlib.h>
#include <kernel.h>

void
	panic(char *file, uint32 line, char *reason)
{
	cli();
	printk("[kernel] panic: %s (%s:%d)\n", reason, file != NULL ? file : "?", line);
	abort();
}

bool
	panic_assert(char *file, uint32 line, char *condition, char *message)
{
	char	*format;

	if (message == NULL)
		format = "[kernel] panic assert: %s:%d\n[kernel] panic assert: Condition not met: %s\n[kernel] panic assert: No message provided.\n";
	else
		format = "[kernel] panic assert: %s:%d\n[kernel] panic assert: Condition not met: %s\n[kernel] panic assert: %s.\n";
	cli();
	printk(format, file != NULL ? file : "?", line, condition, message);
	abort();
	return (false);
}
