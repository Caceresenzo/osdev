#include <common.h>
#include <graphics2d.h>

bool
	g2d_draw_line_vert(t_g2d *g2d, size_t x_start, size_t x_end, size_t y)
{
	size_t	x;

	if (g2d == NULL)
		return (false);
	x = x_start;
	while (x < x_end)
	{
		g2d_set_at(g2d, x, y);
		x++;
	}
	return (true);
}
