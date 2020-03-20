#include <kernel.h>
#include <stdio.h>
#include <kernel/tty.h>

void kernel_main(void) {
	terminal_initialize();
	printf("Hello, kernel World!\n");
	printf("Welcome to the new OS era!");
}
