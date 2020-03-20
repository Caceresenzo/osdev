#include "string.h"

void
	*memcpy(void *dst, const void *src, size_t n)
{
	size_t index;

	if (dst == NULL && src == NULL)
		return (NULL);
	index = 0;
	while (index < n)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}
