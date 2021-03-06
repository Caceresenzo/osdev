#include <arch/i386/vga.h>
#include <common.h>
#include <driver/screen.h>

bool
	screen_apply(t_screen *screen)
{
	size_t	x;
	size_t	y;
	size_t	index;

	if (screen == NULL)
		return (false);
	x = 0;
	while (x < screen->graphics->width)
	{
		y = 0;
		while (y < screen->graphics->height)
		{
			index = screen->graphics->width * y + x;
			vga_put_entry_at(screen->graphics->chars[index],
					screen->graphics->colors[index], x + screen->offset_x,
					y + screen->offset_y);
			y++;
		}
		x++;
	}
	return (true);
}
