#ifndef _PROGRAM_SHELL_H
# define _PROGRAM_SHELL_H

# include <common.h>

typedef struct	s_command
{
	char	*name;
	char	*usage;
	char	*description;
	void	(*handler)(char *, char *);
}				t_command;

char		g_sh_buffer[32];
size_t		g_sh_buffer_len;
t_command	g_commands[6];

void	shell_start(void);
bool	shell_keyboard_callback(uint8 code);

void	cmd_about_handler(char *name, char *args);
void	cmd_clear_handler(char *name, char *args);
void	cmd_echo_handler(char *name, char *args);
void	cmd_desktop_handler(char *name, char *args);
void	cmd_help_handler(char *name, char *args);
void	cmd_sizeof_handler(char *name, char *args);

#endif
