#ifndef _STDIO_H
# define _STDIO_H

# include <sys/cdefs.h>

# define EOF (-1)

# ifdef __cplusplus
extern "C" {
# endif

int		printf(const char* format, ...);
int		putchar(int chr);
int		puts(const char* str);

# ifdef __cplusplus
}
# endif

#endif
