#include <driver/screen.h>

bool
	screen_set_offset(t_screen *screen, size_t offset_x, size_t offset_y)
{
	if (screen == NULL)
		return (false);
	screen->offset_x = offset_x;
	screen->offset_y = offset_y;
	return (true);
}
