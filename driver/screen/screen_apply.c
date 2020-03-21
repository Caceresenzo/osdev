#include <driver/screen.h>

bool
	screen_apply(t_screen *screen)
{
	size_t	x;
	size_t	y;
	size_t	index;

	if (screen == NULL)
		return (false);
	x = screen->offset_x;
	while (x < screen->graphics->width)
	{
		y = screen->offset_y;
		while (y < screen->graphics->height)
		{
			index = screen->graphics->width * y + x;
			terminal_putentryat(screen->graphics->chars[index],
					screen->graphics->colors[index], x, y);
			y++;
		}
		x++;
	}
	return (true);
}
