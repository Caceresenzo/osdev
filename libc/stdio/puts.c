#include <stdio.h>

int
	puts(const char* str) {
	return (printk("%s\n", str));
}
