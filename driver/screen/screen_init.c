#include <driver/screen.h>

bool
	screen_init(t_screen *screen, size_t offset_x, size_t offset_y, t_g2d *g2d)
{
	if (screen == NULL)
		return (false);
	screen_set_offset(screen, offset_x, offset_y);
	screen->graphics = g2d;
	return (true);
}
