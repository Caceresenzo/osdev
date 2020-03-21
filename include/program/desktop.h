#ifndef _PROGRAM_DESKTOP_H
# define _PROGRAM_DESKTOP_H

# include <sys/types.h>
# include <driver/screen.h>
# include <stdbool.h>

typedef struct	s_program
{
	char	*name;
	char	*description;
	void	(*start)(void);
	void	(*loop)(t_screen *);
	bool	(*kb_callback)(t_screen *, t_uchar);
}				t_program;

t_program	g_programs[2];

void	desktop_start(void);
bool	desktop_keyboard_callback(t_uchar code);

#endif
