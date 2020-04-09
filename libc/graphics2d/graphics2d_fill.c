#include <common.h>
#include <graphics2d.h>

bool
	g2d_fill(t_g2d *g2d)
{
	size_t	x;
	size_t	y;

	if (g2d == NULL)
		return (false);
	x = 0;
	while (x < g2d->width)
	{
		y = 0;
		while (y < g2d->height)
		{
			g2d_set_at(g2d, x, y);
			y++;
		}
		x++;
	}
	return (true);
}
