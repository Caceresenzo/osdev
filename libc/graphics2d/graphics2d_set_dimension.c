#include <common.h>
#include <graphics2d.h>

bool
	g2d_set_dim(t_g2d *g2d, size_t width, size_t height)
{
	if (g2d == NULL)
		return (false);
	g2d->width = width;
	g2d->height = height;
	return (true);
}
