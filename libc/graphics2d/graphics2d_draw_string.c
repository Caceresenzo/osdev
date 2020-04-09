#include <common.h>
#include <graphics2d.h>

bool
	g2d_draw_str(t_g2d *g2d, size_t x, size_t y, char *str)
{
	size_t	index;

	if (g2d == NULL)
		return (false);
	index = 0;
	while (str[index])
	{
		g2d->pen_char = (uint8) str[index];
		g2d_set_at(g2d, x + index, y);
		index++;
	}
	return (true);
}
