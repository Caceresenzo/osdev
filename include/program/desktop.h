#ifndef _PROGRAM_DESKTOP_H
# define _PROGRAM_DESKTOP_H

# include <common.h>
# include <driver/screen.h>

typedef struct
{
	char	*name;
	char	*description;
	void	(*start)(void);
	void	(*loop)(t_screen *);
	bool	(*kb_callback)(t_screen *, uint8);
}				t_program;

t_program	g_programs[2];

void	desktop_start(void);
bool	desktop_keyboard_callback(uint8 code);

#endif
