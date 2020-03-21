#include <graphics2d.h>
#include <stddef.h>

static size_t
	get_index(t_g2d *g2d, size_t x, size_t y)
{
	return (g2d->width * y + x);
}

bool
	g2d_set_at(t_g2d *g2d, size_t x, size_t y)
{
	size_t	index;

	if (g2d == NULL || x >= g2d->width || y >= g2d->height)
		return (false);
	index = get_index(g2d, x, y);
	g2d->chars[index] = g2d->pen_char;
	g2d->colors[index] = g2d->pen_color;
	return (true);
}
