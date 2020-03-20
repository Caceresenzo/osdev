#include "string.h"

int
	memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((*str1 == *str2) && n - 1 > 0)
	{
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}
