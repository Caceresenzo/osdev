#ifndef _KEYS_H
# define _KEYS_H

# include <stdbool.h>

# define KEY_ARROW_UP 72
# define KEY_ARROW_DOWN 80
# define KEY_ARROW_LEFT 75
# define KEY_ARROW_RIGHT 77
# define KEY_BACKSPACE 0x0e
# define KEY_ENTER 0x1c
# define KEY_SPACE 57
# define KEY_LEFT_CONTROL 29

# define KEY_Z 44
# define KEY_S 31
# define KEY_Q 16
# define KEY_D 32

typedef struct	s_charset
{
	char	*name;
	char	characters[256];

}				t_charset;

t_charset	g_charsets[1];
t_charset	*g_selected_charset;

bool		charset_use(t_charset *charset);
char		charset_get(int code);

bool		key_states[256];

bool		key_state_set(int code, bool state);
bool		key_state_get(int code);

#endif
