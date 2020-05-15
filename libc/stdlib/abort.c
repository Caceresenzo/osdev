#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))
void abort(void) {
#if defined(__is_libk)
	// TODO: Add proper kernel panic.
	printk("kernel: panic: abort()\n");
#else
	// TODO: Abnormally terminate the process as if by SIGABRT.
	printk("abort()\n");
#endif
	while (1) { }
	__builtin_unreachable();
}
