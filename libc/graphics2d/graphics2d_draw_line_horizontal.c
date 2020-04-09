#include <common.h>
#include <graphics2d.h>

bool
	g2d_draw_line_hor(t_g2d *g2d, size_t x, size_t y_start, size_t y_end)
{
	size_t	y;

	if (g2d == NULL)
		return (false);
	y = y_start;
	while (y < y_end)
	{
		g2d_set_at(g2d, x, y);
		y++;
	}
	return (true);
}
