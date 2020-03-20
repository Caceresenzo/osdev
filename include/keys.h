#ifndef _KEYS_H
# define _KEYS_H

# include <stdbool.h>

typedef struct	s_charset
{
	char	*name;
	char	characters[256];

}				t_charset;

t_charset	g_charsets[1];
t_charset	*g_selected_charset;

bool		charset_use(t_charset *charset);
char		charset_get(int code);

#endif
