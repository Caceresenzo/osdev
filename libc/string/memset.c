#include "string.h"

void
	*memset(void *buf, int c, size_t len)
{
	size_t index;

	index = 0;
	while (index < len)
		((unsigned char *)buf)[index++] = c;
	return (buf);
}
