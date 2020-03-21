#ifndef _DRIVER_SCREEN_H
# define _DRIVER_SCREEN_H

# include <cursor.h>
# include <graphics2d.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct	s_screen
{
	size_t		offset_x;
	size_t		offset_y;
	t_cursor	cursor;
	t_g2d		*graphics;
}				t_screen;

bool	screen_set_offset(t_screen *screen, size_t offset_x, size_t offset_y);
bool	screen_init(t_screen *screen, size_t off_x, size_t off_y, t_g2d *g2d);

bool	screen_apply(t_screen *screen);

#endif
