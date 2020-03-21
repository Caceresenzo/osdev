#ifndef _PROGRAM_JUMPER_H
# define _PROGRAM_JUMPER_H

# include <sys/types.h>
# include <driver/screen.h>
# include <stdbool.h>

void	jumper_start(void);
void	jumper_loop(t_screen *screen);

#endif
