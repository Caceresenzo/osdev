#include <common.h>
#include <stdio.h>

#define PRINT_SIZE(type) printf("%d <- '%s'\n", sizeof(type), #type)

void
	cmd_sizeof_handler(char *name, char *args)
{
	(void) name;
	(void) args;
	PRINT_SIZE(char);
	PRINT_SIZE(short);
	PRINT_SIZE(int);
	PRINT_SIZE(long);
	PRINT_SIZE(long long);
	PRINT_SIZE(int8);
	PRINT_SIZE(int16);
	PRINT_SIZE(int32);
	PRINT_SIZE(int64);
	PRINT_SIZE(size_t);
}
