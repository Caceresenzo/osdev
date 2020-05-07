#include <common.h>
#include <stdio.h>
#include <stdlib.h>
#include <kernel.h>

void
	panic(char *file, uint32 line, char *reason)
{
	cli();
	printf("[kernel] panic: %s (%s:%d)\n", reason, file != NULL ? file : "?", line);
	abort();
}

bool
	panic_assert(char *file, uint32 line, char *condition, char *message)
{
	char	*format;

	if (message == NULL)
		format = "[kernel] panic assert: (%s:%d) -> %s\n";
	else
		format = "[kernel] panic assert: (%s:%d) -> %s: %s\n";
	cli();
	printf(format, file != NULL ? file : "?", line, condition, message);
	abort();
	return (false);
}
