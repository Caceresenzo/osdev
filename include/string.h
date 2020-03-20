#ifndef _STRING_H
# define _STRING_H 1

# include <sys/cdefs.h>
# include <stddef.h>

# ifdef __cplusplus
extern "C" {
# endif

int		memcmp(const void *s1, const void *s2, size_t n);
void	*memcpy(void *dst, const void *src, size_t n);
void	*memmove(void *dst, const void *src, size_t len);
void	*memset(void *buf, int c, size_t len);
size_t	strlen(const char *str);

# ifdef __cplusplus
}
# endif

#endif
